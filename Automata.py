import array
import sys
import graphviz as gv


file = open('texto.txt', 'r')
read_file = file.readlines()
file.close()

a = []
transi = []

for i in range(len(read_file)):
    a.append(read_file[i].strip().split(","))

for i in range(len(a)):
    if(i==0):
        Alpha = a[i]
    if(i==1):
        estados = a[i]
    if (i == 2):
        trans = a[i]
    if (i == 3):
        ini = a[i]
    if (i == 4):
        final = a[i]
for i in range(len(trans)):
    cadena = list(trans[i])
    transi.append(cadena)

print(a)
print(estados)
print(transi)
print(ini)
print(final)


def draw(alafabeto, estados, inicial, transiccion, final):
    print("inicio:", str(inicial))
    g = gv.Digraph(format='svg')
    g.graph_attr['rankdir'] = 'LR'
    g.node('ini', shape="point")
    for e in estados:
        if e in final:
            g.node(e, shape="doublecircle")
        else:
            g.node(e)
        if e in inicial:
            g.edge('ini', e)

    for t in transiccion:
        if t[2] not in alafabeto:
            return 0
        g.edge(t[0], t[1], label=str(t[2]))
    g.render(view=False )



#draw(Alpha, estados, ini, transi, final)


def printMatriz(Matriz):
    for i in range(len(Matriz)):
        print(*Matriz[i])


def getW(estado, letra, matriz, alpha):
    #La funcion nos retorna  el estado dada la tabla de transicion en el estado "estado" para una entrada "letra" en el alfabeto
    #alpha
    j = int(estado)
    pos = 0
    for i in range(len(alpha)):
        if alpha[i] == letra:
            return matriz[j][i]


print("Alfabeto:")
print(Alpha)
print("Estados")
print(len(estados))
print("Los estados son los elementos: ")
for j in range(len(estados)):
    print(estados[j])

Matriz = []
for i in range(len(estados)):
    Matriz.append([i])
    for j in range(len(Alpha) - 1):
        Matriz[i].append(None)


for t in transi:
    i = int(t[0])
    aux = t[2]
    j = Alpha.index(aux)
    S = t[1]
    Matriz[i][j] = S

printMatriz(Matriz)
print("Estado final")
for i in range (len(final)):
    print(final[i])


print("Ingrese el numero de pruebas ")
N = int(sys.stdin.readline())
for i in range(N):
    print("INGRESE LA PALABRA")
    S = (sys.stdin.readline().strip())
    estadoa = 0
    print("Estado INICIAL q_" + str(estadoa))  # ESTADO INICIAL
    for j in range(len(S)):
        estadoa = getW(estadoa, S[j], Matriz, Alpha)
        print("Estado actual q_" + str(estadoa)) #RECORRIDO DE ESTADOS

    if str(estadoa) in final : #se hace el cast porque estadosf los reconoce como strings
        print("ACEPTA LA PALARBA: " + S.strip())
    else:
        print("NO LO ACEPTA: " + S)



