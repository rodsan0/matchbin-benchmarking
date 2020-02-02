import pandas as pd
import seaborn as sns
import subprocess

import csv

# constants
filename = "graph.png"
repetitions = 100

# generate dataset

# run with lock
lock_results = []

for i in range(0, repetitions):
        output = subprocess.run("./benchmark_lock.out", stdout=subprocess.PIPE)
        lock_results.append(int(output.stdout))
print(lock_results)

# run without lock
nolock_results = []

for i in range(0, repetitions):
        output = subprocess.run("./benchmark.out", stdout=subprocess.PIPE)
        nolock_results.append(int(output.stdout))
print(nolock_results)

df = pd.DataFrame({'Lock': lock_results,
                   'No lock': nolock_results})
ax = sns.barplot(data=df)
fig = ax.get_figure()
fig.savefig(filename)

# write data to file for future reference
with open('results.csv', 'w') as file:
        writer = csv.writer(file)

        writer.writerow(['Lock', 'No lock'])

        for i in range (0, repetitions):
                writer.writerow([lock_results[i], nolock_results[i]])