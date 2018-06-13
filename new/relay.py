import matplotlib.pyplot as plt
import numpy as np
def fun(a):
    y = np.loadtxt(a)[:-3]
    x=range(len(y))
    plt.plot(x,y, label='crypto value!')
    plt.xlabel('x')
    plt.ylabel('y')
    st=a[4:-4]+"coin"
    plt.title(st)
    plt.legend()
    if(a=="predbit.txt"):
        plt.savefig("bit.png")
    elif(a=="predlite.txt"):
        plt.savefig("lite.png")
    else:
        plt.savefig("doge.png")
    plt.show()
a="predbit.txt"
fun(a)
a="predlite.txt"
fun(a)
a="preddoge.txt"
fun(a)
