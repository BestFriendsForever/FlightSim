main: main.c
	gcc main.c SOIL.c image_DXT.c image_helper.c stb_image_aug.c camera.c alg.c map.c math3d.c tga.c -o main -lGL -lGLU -lglut

heightMapTest: heightMap.c
	gcc heightMap.c SOIL.c image_DXT.c image_helper.c stb_image_aug.c camera.c alg.c map.c math3d.c tga.c -o heightMapTest -lGL -lGLU -lglut

