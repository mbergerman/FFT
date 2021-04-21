#%%
import matplotlib.pyplot as plt
from numpy import sin, pi
from cmath import phase
import os

def stringToComplex(s):
    s = s.replace('\n', '')
    s = s.replace('j', '')
    s = s.replace(' ', '')
    real, imag = tuple( s.split('+') )
    real, imag = float(real), float(imag)
    return complex(real, imag)

def f(x):
    y = [(1/n) * sin(2*pi*100*n*x) for n in range(1, 10, 2)]
    return sum(y)

#%%
n = 2**12
data = [ f(t/n) for t in range(n) ]

plt.figure(figsize = (12, 5))
plt.plot(data)
plt.grid()
plt.savefig('images/input.png', dpi=300)
plt.show()

python_dir = os.path.dirname(__file__)
input_path = os.path.join(python_dir, "data/input.txt")
output_path = os.path.join(python_dir, "data/output.txt")
buildandrun_path = os.path.join(python_dir, "BuildAndRun.bat")

with open(input_path, "w+") as file:
    file.write(str(n) + '\n')
    for x in data:
        file.write(str(x) + '\n')

#%%
os.system(buildandrun_path)

#%%
with open(output_path, "r") as file:
    data.clear()
    for x in file.readlines():
        data.append( stringToComplex(x) )
        
    fig, (ax1, ax2) = plt.subplots(2, 1, figsize = (12, 8))
    ax1.plot([abs(x) for x in data])
    ax1.set_title('Valor absoluto')
    ax1.grid()
    ax2.plot([phase(x) for x in data])
    ax2.set_title('Fase')
    ax2.grid()

    plt.tight_layout()
    plt.savefig('images/output.png', dpi=300)
    plt.show()

# %%
