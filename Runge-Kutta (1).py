import math

def truth(i):
    return 24*math.exp(-i)

def f(_x,_y):
    return -1*_y
    
if __name__ == '__main__':
    y0 = 24
    step = 0.001 #dt here
    right = 100
    arry = []
    arry.append(y0)
    for x in range(right):
        yx = arry[x] 
        print (str(yx)+'~'+str(truth(x*step)))
        k1 = f(x*step,yx)
        k2 = f(x*step+step/2,yx+k1*step/2)
        k3 = f(x*step+step/2,yx+k2*step/2)
        k4 = f(x*step+step,yx+k3*step)
        det = step*(k1+2*k2+2*k3+k4)/6
        arry.append(yx+det)
    