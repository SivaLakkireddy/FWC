import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
#local imports
#from line.funcs import *
#from triangle.funcs import *
#from conics.funcs import circ_gen
def line_gen(A,B):
   len =10
   dim = A.shape[0]
   x_AB = np.zeros((dim,len))
   lam_1 = np.linspace(0,1,len)
   for i in range(len):
     temp1 = A + lam_1[i]*(B-A)
     x_AB[:,i]= temp1.T
   return x_AB

def dir_vec(A,B):
   return B-A
def norm_vec(A,B):
   return np.matmul(omat, dir_vec(A,B))

#Input parameters
theta =45* np.pi/180
a=8
k=3.5
e2=np.array(([0,1]))
C=np.array([8,0])
B=np.array([0,0])
#O =np.array(([1,-1],[-k,-k+2*a*np.cos(theta)]))
#D=np.array(([-k,a**2]))
#P=np.linalg.solve(O,D)
#d=a*np.cos(theta)
#p=d/k
#f=1-p
q1=np.array([[1,1],[1,-1]])
q2=np.array(([-a**2/k,-k]))
q=np.dot(q1,q2)
#r=1/(2*f) 
#s=np.transpose(e2)
#t=np.dot(s,q) 
#b=r*t
#g=1/(2*(1-(a*np.cos(theta)/k)))  
b=1/(2*(1-(a*np.cos(theta)/k)))*np.dot(np.transpose(e2),q)
#q=np.dot(np.array([[1,1],[1,-1]]),np.array(([-k/a**2,-k])))
#b=(1/2*(1-p))*e2.transpose()*q
#b=np.(1/(2*(1-(a*np.cos(theta)/k)))*(np.transpose(e2)*np.array([[1,1],[1,-1]])*np.array(([-a^2/k,-k]))
A=np.array(([b*np.cos(theta),b*np.sin(theta)]))
print(A)
l=(np.linalg.norm(B-A))
m=(np.linalg.norm(A-C))                   
#print(round(l-m,1))
##Generating all lines
x_BC = line_gen(B,C)
x_AB = line_gen(A,B)
x_CA = line_gen(C,A)

#Plotting all lines
plt.plot(x_CA[0,:],x_CA[1,:],label='$b$')
plt.plot(x_AB[0,:],x_AB[1,:],label='$c$')
plt.plot(x_BC[0,:],x_BC[1,:],label='$a$')

#Labeling the coordinates
tri_coords = np.vstack((C,B,A)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['C','B','A']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(0,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
plt.savefig('/sdcard/fwc/11.2.2/figs/triangle.pdf')
#subprocess.run(shlex.split("termux-open  /sdcard/FWC/matrices/matrix.pdf"))
#else
#plt.show()
