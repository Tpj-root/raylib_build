import os

def create_obj_file():
    obj_content = """mtllib cube.mtl
v -0.5 -0.5 -0.5
v  0.5 -0.5 -0.5
v  0.5  0.5 -0.5
v -0.5  0.5 -0.5
v -0.5 -0.5  0.5
v  0.5 -0.5  0.5
v  0.5  0.5  0.5
v -0.5  0.5  0.5

vt 0.0 0.0
vt 1.0 0.0
vt 1.0 1.0
vt 0.0 1.0

vn 0.0 0.0 -1.0
vn 0.0 0.0 1.0
vn 0.0 -1.0 0.0
vn 0.0 1.0 0.0
vn -1.0 0.0 0.0
vn 1.0 0.0 0.0

usemtl Rubik
f 1/1/1 2/2/1 3/3/1 4/4/1
f 5/1/2 8/2/2 7/3/2 6/4/2
f 1/1/3 5/2/3 6/3/3 2/4/3
f 2/1/6 6/2/6 7/3/6 3/4/6
f 3/1/4 7/2/4 8/3/4 4/4/4
f 5/1/5 1/2/5 4/3/5 8/4/5"""
    
    with open("cube.obj", "w") as obj_file:
        obj_file.write(obj_content)

def create_mtl_file():
    mtl_content = """newmtl Rubik
Ka 1.0 1.0 1.0
Kd 1.0 1.0 1.0
Ks 0.0 0.0 0.0
d 1.0
illum 1
map_Kd rubik_texture.png"""
    
    with open("cube.mtl", "w") as mtl_file:
        mtl_file.write(mtl_content)

if __name__ == "__main__":
    create_obj_file()
    create_mtl_file()
    print("Cube .obj and .mtl files created successfully.")
