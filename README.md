# Proyecto 2do Parcial POO y Avanzada

El objetivo de esta actividad es generar un video usando clases propias y clases de librerias externas como FTXUI para crear una animacion usando codigo ASCII

## Instrucciones
- Generar una animacion utilizando como base el ejemplo de este repositorio
- Grabar la pantalla una vez ejecutado el video
- Subir el video y la URL de su repositorio a classroom
- Si tienen dudas escribir en el grupo de whatsapp

## Dependencias

### Compilar libreria ftxui

Si se perdio su codespace o no cuentan con la libreria FTXUI seguir los pasos a continuacion, son los mismos que hicimos en clase

Pasos:

1. Clona el repositorio de ftxui:
	```bash
	git clone https://github.com/ArthurSonzogni/ftxui.git
	cd ftxui
	```

2. Crea el directorio de compilación y compila:
	```bash
	mkdir build
	cd build
	cmake ..
	make
	```

3. Instala ftxui en el sistema:
	```bash
	sudo make install
    cd ../..
	```

Esto compilará la biblioteca ftxui y sus ejemplos. Puedes encontrar más información en la [documentación oficial](https://github.com/ArthurSonzogni/ftxui).