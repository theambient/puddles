#!/usr/local/bin/python

import numpy as np
import subprocess
import time
import matplotlib.pyplot as plt

stat = []

N = range(10, 70, 5)

print N

# for n in N:

#     subprocess.check_call(['./generator', '0', str(n), str(n)], stdout=open('/tmp/123', 'w'))
#     t0 = time.time()
#     subprocess.check_call(['./puddles', '/tmp/123', '/dev/null'])
#     t1 = time.time()

#     elapsed = t1 - t0

#     stat.append(elapsed)

stat = [0.009881973266601562, 0.020556926727294922, 0.09976887702941895, 0.21130585670471191, 0.6991639137268066, 1.4706299304962158, 3.574915885925293, 6.844218969345093, 15.158626079559326, 29.420950174331665, 39.243988037109375, 71.27539300918579]
print stat

plt.plot(N, stat, '.')

for deg in range(2, 10):
    fit = np.polyfit(N, stat, deg)
    p = np.poly1d(fit)
    # print 'deg {}: {}'.format(deg, fit)
    xp = np.linspace(10, 70, 100)

    poly_str = map(lambda (i, t): '{:.2f} x^{}'.format(t, i), enumerate(fit))
    label = ' + '.join(poly_str)
    plt.plot(xp, p(xp), label=label)

plt.legend()
plt.show()

