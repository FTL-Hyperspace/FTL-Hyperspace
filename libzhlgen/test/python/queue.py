
while True:
    inp = input("1>")


    classtype = "std__queue"
    classname = inp.replace("::", "_")

    print("""
struct {0}_{2}{3} 
{{
    void* _map;
    int _map_size;
    void* _start_cur;
    void* _start_first;
    void* _start_last;
    void* _start_node;
    void* _finish_cur;
    void* _finish_first;
    void* _finish_last;
    void* _finish_node;
}}
    """.format(classtype, classname, len(classname.replace("*", "Z1")), classname.replace("*", "Z1")))
    
