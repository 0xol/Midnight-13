import os

def compile(filename):
    extension = filename.split(".")
    path = extension[0].split("/")

    if extension[1] == "c":
        os.system("gcc -I src/include -c " + filename + " -o bin/" + path[-1] + ".o")
        print("[CC]  " + path[-1] + "." + extension[1])

    if extension[1] == "cpp":
        os.system("g++ -I src/include -c " + filename + " -o bin/" + path[-1] + ".o")
        print("[C++] " + path[-1] + "." + extension[1])

def linkLinux():
    print("[LD]  midnight")
    os.system("gcc bin/*.o -o midnight -no-pie -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -DPLATFORM_DESKTOP -Os")

def linkWin():
    print("[LD]  midnight.exe")
    os.system("gcc bin/*.o -o midnight.exe -lraylib -lws2_32 -lopengl32 -lgdi32 -lwinmm -DPLATFORM_DESKTOP -Os")

def compileDir(dir):
    for file in os.listdir(dir):
        if os.path.isdir(dir + "/" + file) == True:
            #recursive time
            compileDir(dir + "/" + file)
        if os.path.isdir(dir + "/" + file) == False:
            compile(dir + "/" + file)

def buildLinux():
    compileDir(os.getcwd() + "/src")
    linkLinux()

def buildWin():
    compileDir(os.getcwd() + "/src")
    linkWin()