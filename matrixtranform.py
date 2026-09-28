import matplotlib.pyplot as plt
import sympy as sp
from pathlib import Path


def read_input(filename):
    matrix = []
    points = []
    section = None

    with open(filename, "r") as f:
        for line in f:
            line = line.strip()
            if not line:
                continue

            if line.startswith("#"):
                section = line[1:].strip().lower()
                continue

            row = [float(x) for x in line.replace(",", " ").split()]

            if section == "matrix":
                matrix.append(row)
            elif section == "points":
                points.append(row)

    return matrix, points


# Looks for data.txt next to this script, regardless of where you run it from
input_file = Path(__file__).parent / "matrixdata.txt"
matrix, points = read_input(input_file)

def matrix_transform(matrix, points):
    new_point =[]
    new_point_list=[]
    for k in points:
        new_point = []
        for i in matrix:
                a = i[0]*k[0] + i[1]*k[1] + i[2]*k[2]
                new_point.append(a)
        new_point_list.append(new_point)
    


    return new_point_list

def find_eigen_values(matrix):
    a = sp.Matrix(matrix)
    I = sp.eye(3)
    l = sp.symbols('l')
    char_matrix = a - l*I
    det_expr = char_matrix.det() 
    eignenvalues = sp.solve(det_expr,l) 
    return eignenvalues


def find_eigen_vector(matrix,eigenvalues):
    a = sp.Matrix(matrix)
    I= sp.eye(3)
    eigenvectors = {}
    for val in eigenvalues:

        char_matrix = a - val*I
        null_space = char_matrix.nullspace()
        eigenvectors[val] = null_space

    return eigenvectors

def build_V(eigenvectors_dict):
    columns = []
    for val, vecs in eigenvectors_dict.items():
        for v in vecs:
            columns.append(v)
    V = sp.Matrix.hstack(*columns)
    return V

def to_eigenbasis(point, V_inv):
    p = sp.Matrix(point)
    c = V_inv * p
    return [float(x) for x in c]

new_p = matrix_transform(matrix,points)

eigenvalues = find_eigen_values(matrix)
eigenvectors = find_eigen_vector(matrix,eigenvalues)
v= build_V(eigenvectors)


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')


xs = [p[0] for p in points]
ys = [p[1] for p in points]
zs = [p[2] for p in points]


xs2 = [p[0] for p in new_p]
ys2 = [p[1] for p in new_p]
zs2 = [p[2] for p in new_p]

ax.scatter(xs2, ys2, zs2, color='red', label='transformed')
ax.scatter(xs, ys, zs, color='blue', label='original')



fig = plt.figure(figsize=(12, 5))

ax2 = fig.add_subplot(122, projection='3d')  
V_inv = v.inv()

eigen_points = [to_eigenbasis(p, V_inv) for p in points]

c1 = [p[0] for p in eigen_points]
c2 = [p[1] for p in eigen_points]
c3 = [p[2] for p in eigen_points]

ax2.scatter(c1, c2, c3, color='blue', label='original (eigen basis)')


plt.show()

                