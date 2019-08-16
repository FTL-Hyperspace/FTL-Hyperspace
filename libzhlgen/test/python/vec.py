
while True:
    inp = input(">")

    classtype = "std__vector"
    classname = inp.replace("::", "_")

    print("""
struct {0}_{2}{3} 
{{
    {1}* _start;
    {1}* _finish;
    {1}* _end;
}}
    """.format(classtype, classname, len(classname.replace("*", "Z1")), classname.replace("*", "Z1")))
    
