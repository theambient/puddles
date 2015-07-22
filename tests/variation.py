#!/usr/local/bin/python

import numpy as np
import subprocess
import time

percentiles = [0.5, 0.6, 0.7, 0.8, 0.9, 0.95, 0.99, 1]
stat = []

for seed in range(1000):

    subprocess.check_call(['./generator', str(seed), '50', '50'], stdout=open('/tmp/123', 'w'))
    t0 = time.time()
    subprocess.check_call(['./puddles', '/tmp/123', '/dev/null'])
    t1 = time.time()

    elapsed = t1 - t0

    stat.append(elapsed)

mean = np.average(stat)
stddev = np.std(stat)

print "range: {}...{}".format(np.amin(stat), np.amax(stat))
print "v = {} +- {}".format(mean, stddev)
print "rel stddev = {:.2f}%".format(mean/stddev)
print "percentiles:"

p = np.percentile(stat, percentiles)
for i, _ in enumerate(p):
    print '\t{}% <= {}'.format(percentiles[i]*100, p[i])
