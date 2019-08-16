
while True:
    inp1 = input("1>")
    inp2 = input("2>")


    classtype = "std__pair"
    classname1 = inp1
    classname2 = inp2

    pair = classname1.replace("::", "_").replace("*", "Z1") + "___" + classname2.replace("::", "_").replace("*", "Z1")

    print("""
struct {0}_{3}{4} 
{{
    {1} _first;
    {2} _second;
}}
    """.format(classtype, classname1, classname2, len(pair), pair))
    
