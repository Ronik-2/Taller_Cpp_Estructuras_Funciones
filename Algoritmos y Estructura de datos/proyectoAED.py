import heapq

#  Estructuras 
grafo = {}
seleccion_cliente = []

zonas_de_entrega = {
    "Costa": {
        "Guayas": ["Guayaquil", "Playas"],
        "Manabí": ["Manta", "Puerto López"]
    },
    "Sierra": {
        "Pichincha": ["Quito", "Panecillo"],
        "Tungurahua": ["Baños de Agua Santa"],
        "Ibarra": ["Otavalo", "Yahuarcocha"]
    },
    "Oriente": {
        "Napo": ["Tena"],
        "Pastaza": ["Puyo"]
    }
}

usuarios_predefinidos = [
    {
        "nombre": "Alex Anguie",
        "identificacion": "1234567890",
        "edad": "20",
        "correo": "alexanguie@gmail.com",
        "contrasena": "Admin1234",
        "rol": "Administrador"
    }
]

def crear_archivo_centros():
    with open("centros.txt", "w") as archivo:
        archivo.write("Guayaquil, Manta, 45.1, 30\n")
        archivo.write("Manta, Quito, 40.3, 40\n")
        archivo.write("Napo, Loja, 286.9, 70\n")
        archivo.write("Ibarra, Napo, 408.5, 120\n")
        archivo.write("Santo Domingo, Tena, 267.7, 65\n")
        archivo.write("Quito, Latacunga, 353, 30\n")
        archivo.write("Santo Domingo, Quito, 566, 55\n")
        archivo.write("Guayaquil, Quito, 309.5, 80\n")
        archivo.write("Puyo, Riobamba, 250.4, 20\n")
        archivo.write("Guayaquil, Machala, 123, 25\n")

def leer_datos():
    rutas = []
    try:
        with open("centros.txt", "r") as archivo:
            for linea in archivo:
                L_partida, L_destino, distancia, costo = linea.strip().split(",")
                rutas.append((L_partida.strip(), L_destino.strip(), float(distancia.strip()), float(costo.strip())))
    except FileNotFoundError:
        crear_archivo_centros()
        return leer_datos()
    return rutas

def guardar_centros():
    with open("centros.txt", "w") as f:
        for o, destinos in grafo.items():
            for d, datos in destinos.items():
                f.write(f"{o},{d},{datos['distancia']},{datos['costo']}\n")
    print("Cambios guardados en 'centros.txt'.")

#Grafo 
def lista_adyacencia_para_dijkstra(rutas):
    grafo_local = {}
    for origen, destino, distancia, costo in rutas:
        if origen not in grafo_local:
            grafo_local[origen] = {}
        if destino not in grafo_local:
            grafo_local[destino] = {}
        grafo_local[origen][destino] = {'distancia': distancia, 'costo': costo}
        grafo_local[destino][origen] = {'distancia': distancia, 'costo': costo}
    return grafo_local

def agregar_conexion(origen, destino, distancia, costo):
    if origen not in grafo:
        grafo[origen] = {}
    if destino not in grafo:
        grafo[destino] = {}
    grafo[origen][destino] = {'distancia': distancia, 'costo': costo}
    grafo[destino][origen] = {'distancia': distancia, 'costo': costo}

# Dijkstra 
def _dijkstra(inicio, tipo_costo='costo'):
    distancias = {nodo: float('inf') for nodo in grafo}
    predecesores = {nodo: None for nodo in grafo}
    distancias[inicio] = 0
    cola_prioridad = [(0, inicio)]
    while cola_prioridad:
        costo_actual, nodo_actual = heapq.heappop(cola_prioridad)
        if costo_actual > distancias[nodo_actual]:
            continue
        for vecino, datos in grafo[nodo_actual].items():
            costo_arista = datos[tipo_costo]
            nuevo_costo = costo_actual + costo_arista
            if nuevo_costo < distancias[vecino]:
                distancias[vecino] = nuevo_costo
                predecesores[vecino] = nodo_actual
                heapq.heappush(cola_prioridad, (nuevo_costo, vecino))
    return distancias, predecesores

def consultar_ruta_optima(origen, destino):
    distancias_costo, predecesores = _dijkstra(origen, 'costo')
    distancias_dist, _ = _dijkstra(origen, 'distancia')
    if distancias_costo[destino] == float('inf'):
        return [], f"No hay ruta disponible de {origen} a {destino}."
    ruta = []
    actual = destino
    while actual:
        ruta.append(actual)
        actual = predecesores[actual]
    ruta.reverse()
    costo_total = distancias_costo[destino]
    distancia_total = distancias_dist[destino]
    mensaje = (
        "La mejor ruta es:\n"
        f"Ruta: {' -> '.join(ruta)}\n"
        f"Distancia total: {distancia_total:.2f} km\n"
        f"Costo total: ${costo_total:.2f} USD"
    )
    return ruta, mensaje

# Validación de usuarios
def validar_contrasena(contrasena):
    tiene_mayuscula = any(c.isupper() for c in contrasena)
    tiene_numero = any(c.isdigit() for c in contrasena)
    return len(contrasena) >= 8 and tiene_mayuscula and tiene_numero

def registro_usuario():
    nombre = input("Ingrese su nombre y apellido: ").strip()
    while True:
        identificacion = input("Ingrese su identificacion (10 dígitos): ").strip()
        if identificacion.isdigit() and len(identificacion) == 10:
            break
        print("Identificación inválida. Debe tener 10 dígitos.")
    while True:
        edad = input("Ingrese su edad (1-99): ").strip()
        if edad.isdigit() and 1 <= int(edad) <= 99:
            break
        print("Edad invalida.")
    while True:
        correo = input("Ingrese su correo (@gmail.com o @epn.edu.ec): ").strip()
        if (correo.endswith("@gmail.com") or correo.endswith("@epn.edu.ec")):
            try:
                with open("usuarios.txt", "r") as f:
                    if correo in f.read():
                        print("Correo ya registrado.")
                        continue
            except FileNotFoundError:
                pass
            break
        print("Correo inválido.")
    contrasena = input("Ingrese contraseña segura: ").strip()
    while not validar_contrasena(contrasena):
        print("Contraseña inválida (mínimo 8, mayúscula y número).")
        contrasena = input("Ingrese contraseña segura: ").strip()
    with open("usuarios.txt", "a") as f:
        f.write(f"{nombre},{identificacion},{edad},{correo},{contrasena},Cliente\n")
    print("Registro exitoso.")

def iniciar_sesion():
    usuario = input("Usuario: ").strip()
    contrasena = input("Contraseña: ").strip()
    for u in usuarios_predefinidos:
        if usuario == u["correo"] and contrasena == u["contrasena"]:
            print("Inicio sesión exitoso.")
            return u["rol"], u["nombre"].split()[0]
    try:
        with open("usuarios.txt", "r") as f:
            for linea in f:
                nombre, iden, edad, correo, clave, rol = linea.strip().split(",")
                if usuario == correo and contrasena == clave:
                    print("Inicio sesión exitoso.")
                    return rol, nombre.split()[0]
    except FileNotFoundError:
        pass
    print("Credenciales incorrectas.")
    return None, None

# Ordenamientos 
def burbuja(lista):
    n = len(lista)
    for i in range(n):
        for j in range(0, n-i-1):
            if lista[j].lower() > lista[j+1].lower():
                lista[j], lista[j+1] = lista[j+1], lista[j]
    return lista
def seleccion(lista):
    n = len(lista)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if lista[j].lower() < lista[min_idx].lower():
                min_idx = j
        lista[i], lista[min_idx] = lista[min_idx], lista[i]
    return lista
def merge_sort(lista):
    if len(lista) <= 1:
        return lista
    mid = len(lista)//2
    left = merge_sort(lista[:mid])
    right = merge_sort(lista[mid:])
    return merge(left, right)
def merge(left, right):
    result = []
    i = j = 0
    while i < len(left) and j < len(right):
        if left[i].lower() <= right[j].lower():
            result.append(left[i])
            i += 1
        else:
            result.append(right[j])
            j += 1
    result.extend(left[i:])
    result.extend(right[j:])
    return result

#  Menú Administrador
def menu_administrador():
    while True:
        print("\n--- MENÚ ADMINISTRADOR ---")
        print("1. Agregar/Actualizar ciudad")
        print("2. Listar ciudades")
        print("3. Buscar ciudad")
        print("4. Eliminar ciudad")
        print("5. Guardar cambios")
        print("6. Salir")
        op = input("Opción: ").strip()
        if op == "1":
            o = input("Origen: ").strip()
            d = input("Destino: ").strip()
            dist = float(input("Distancia: "))
            costo = float(input("Costo: "))
            agregar_conexion(o,d,dist,costo)
            print(f"Conexión {o} ↔ {d} agregada/actualizada.")
        elif op == "2":
            ciudades = list(grafo.keys())
            metodo = input("Ordenar: 1-Burbuja 2-Selección 3-Merge: ").strip()
            if metodo == "1":
                ciudades = burbuja(ciudades)
            elif metodo == "2":
                ciudades = seleccion(ciudades)
            elif metodo == "3":
                ciudades = merge_sort(ciudades)
            for i,c in enumerate(ciudades,1):
                print(f"{i}. {c}")
        elif op == "3":
            nombre = input("Ciudad a buscar: ").strip()
            encontrados = [c for c in grafo if nombre.lower() in c.lower()]
            if encontrados:
                for c in encontrados:
                    print(f"{c}:")
                    for d, datos in grafo[c].items():
                        print(f"   -> {d}: {datos['distancia']} km | ${datos['costo']}")
            else:
                print("No encontrada.")
        elif op == "4":
            c = input("Ciudad a eliminar: ").strip()
            if c in grafo:
                del grafo[c]
                for destinos in grafo.values():
                    if c in destinos:
                        del destinos[c]
                print(f"{c} eliminada.")
            else:
                print("No existe.")
        elif op == "5":
            guardar_centros()
        elif op == "6":
            break
        else:
            print("Opción inválida.")

#  Menú Cliente 
def mostrar_arbol_zonas():
    print("\n--- ZONAS DEL MAPA ---")
    for region, provincias in zonas_de_entrega.items():
        print(f"[{region}]")
        for prov, ciudades in provincias.items():
            disp = [c for c in ciudades if c in grafo]
            if disp:
                print(f"  - {prov}: {', '.join(disp)}")

def seleccionar_ciudades():
    while True:
        ciudad = input("Ciudad a visitar (ENTER para terminar): ").strip()
        if ciudad == "":
            if len(seleccion_cliente) < 2:
                print("Debe seleccionar al menos 2 ciudades.")
                continue
            break
        if ciudad in grafo:
            seleccion_cliente.append(ciudad)
            print(f"'{ciudad}' añadida.")
        else:
            print("Ciudad no registrada.")
def listar_ciudades_seleccionadas():
    if not seleccion_cliente:
        print("No hay ciudades seleccionadas.")
        return
    # Mostrar ordenadas alfabéticamente
    ordenadas = sorted(seleccion_cliente, key=lambda x: x.lower())
    print("\nCiudades seleccionadas (ordenadas alfabéticamente):")
    for i, ciudad in enumerate(ordenadas, start=1):
        print(f"{i}. {ciudad}")
    total_costo = 0
    total_distancia = 0
    for i in range(len(seleccion_cliente)-1):
        inicio = seleccion_cliente[i]
        fin = seleccion_cliente[i+1]
        # Uso de Dijkstra
        distancias_costo, predecesores_costo = _dijkstra(inicio, 'costo')
        distancias_dist, _ = _dijkstra(inicio, 'distancia')

        if distancias_costo[fin] == float('inf') or distancias_dist[fin] == float('inf'):
            print(f"No hay ruta disponible de {inicio} a {fin}.")
            continue

        total_costo += distancias_costo[fin]
        total_distancia += distancias_dist[fin]

    print(f"\nCosto total: ${total_costo:.2f} | Distancia total: {total_distancia:.2f} km")


def actualizar_o_eliminar_ciudad():
    if not seleccion_cliente:
        print("No hay ciudades seleccionadas.")
        return
    nombre = input("Ciudad a modificar: ").strip()
    if nombre not in seleccion_cliente:
        print("No encontrada.")
        return
    accion = input("Actualizar (A) o Eliminar (E): ").upper()
    if accion == "E":
        seleccion_cliente.remove(nombre)
    elif accion == "A":
        nueva = input("Nuevo nombre: ").strip()
        if nueva in grafo:
            idx = seleccion_cliente.index(nombre)
            seleccion_cliente[idx] = nueva
        else:
            print("Ciudad no registrada.")

def guardar_seleccion_cliente(nombre_cliente):
    if not seleccion_cliente:
        print("Nada que guardar.")
        return
    with open(f"rutas-{nombre_cliente.lower()}.txt","w") as f:
        for c in seleccion_cliente:
            f.write(c+"\n")
    print("Guardado.")
def cargar_seleccion_cliente(nombre_cliente):
    seleccion_cliente.clear() 
    try:
        with open(f"rutas-{nombre_cliente.lower()}.txt", "r") as f:
            for linea in f:
                ciudad = linea.strip()
                if ciudad in grafo: 
                    seleccion_cliente.append(ciudad)
    except FileNotFoundError:
        pass  
def menu_cliente(nombre_cliente):
    cargar_seleccion_cliente(nombre_cliente)
    while True:
        print("\n--- MENÚ CLIENTE ---")
        print("1. Ver mapa")
        print("2. Consultar ruta óptima")
        print("3. Explorar zonas")
        print("4. Seleccionar ciudades")
        print("5. Listar ciudades seleccionadas y costo total")
        print("6. Modificar selección")
        print("7. Guardar selección")
        print("8. Cerrar sesión")
        op = input("Opción: ").strip()
        if op == "1":
            for o,destinos in grafo.items():
                for d,datos in destinos.items():
                    print(f"{o} -> {d}: {datos['distancia']} km | ${datos['costo']}")
        elif op == "2":
            o = input("Origen: ").strip()
            d = input("Destino: ").strip()
            if o in grafo and d in grafo:
                _,info = consultar_ruta_optima(o,d)
                print(info)
            else:
                print("Una o ambas ciudades no existen.")
        elif op == "3":
            mostrar_arbol_zonas()
        elif op == "4":
            seleccionar_ciudades()
        elif op == "5":
            listar_ciudades_seleccionadas()
        elif op == "6":
            actualizar_o_eliminar_ciudad()
        elif op == "7":
            guardar_seleccion_cliente(nombre_cliente)
        elif op == "8":
            break
        else:
            print("Opción inválida.")

if __name__ == "__main__":
    rutas = leer_datos()
    grafo = lista_adyacencia_para_dijkstra(rutas)

    while True:
        print("\n--- BIENVENIDO AL SISTEMA ---")
        print("1. Iniciar sesión")
        print("2. Registrarse")
        print("3. Salir")
        opcion = input("Seleccione opción: ").strip()
        if opcion == "1":
            rol,nombre = iniciar_sesion()
            if rol=="Administrador":
                menu_administrador()
            elif rol=="Cliente":
                menu_cliente(nombre)
        elif opcion=="2":
            registro_usuario()
        elif opcion=="3":
            print("Gracias por usar el sistema. ¡Hasta pronto!")
            break
        else:
            print("Opción inválida.")
