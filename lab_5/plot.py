from subprocess import run, PIPE
import matplotlib.pyplot as plt
import numpy as np

def process(n, algo):
    p = run(f"build/lab5_2 {n} 5 -a{algo} -ftime -odesc", shell=True, stdout=PIPE)
    return float(p.stdout.strip().decode()) * 1000

quick_s = []
quick_l = []
shell_s = []
xx = list(range(1, 1001))


for n in xx:
    quick_s.append(process(n, "quick_s"))
    quick_l.append(process(n, "quick_l"))
    shell_s.append(process(n, "shell"))

# Sort results
plt.plot(xx, quick_s, label=r'Self-implemented qsort ($n * \log n$)')
plt.plot(xx, quick_l, label=r'Library qsort ($n * \log n$)')
plt.plot(xx, shell_s, label=r'Shell sort ($n^2$)')
plt.xlabel("Elements in array")
plt.ylabel("Sort time")
plt.legend()
plt.savefig("sort_res.pdf")

plt.cla()

# Sorting complexity
xx2 = np.linspace(1, 100, 100)
plt.plot(xx2, xx2 * np.log2(xx2), label=r'$n * \log(n)$')
plt.plot(xx2, xx2 * xx2, label=r'$n^2$')
plt.xlabel("x")
plt.ylabel("y")
plt.legend()
plt.savefig("funcs.pdf")