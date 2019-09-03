import idautils, idc, ida_bytes, tempfile, sys, os
def main():
    FUNCTION_NAME = 'StarMap'
    cursor = 0
    real_names = []
    addresses = []
    names = idautils.Names() # tuple of all functions

        # obtains function names, and demangles if possible
    print "File saving to: " + os.getcwd() + "\output.txt"
    for addr, name in names:
        demangled = idc.demangle_name(name, get_inf_attr(INF_SHORT_DN))
        if isinstance(demangled, str):
            real_names.append(demangled)
        else:
            real_names.append(name)
        addresses.append(addr)
    with open("output.txt", "w") as fpw:
        first = True # this is to ensure zhl formatting is correct
        for i, rn in enumerate(real_names):
            if rn.startswith(FUNCTION_NAME):
                cursor = addresses[int(real_names.index(rn))]
                func_bytes = []
                tmp_bytes = []
                with tempfile.SpooledTemporaryFile(21, "wb+") as tmp:
                    tmp.write(ida_bytes.get_bytes(cursor, 20))
                    tmp.seek(0)
                    for j in range(20):
                        tmp_bytes.append(tmp.read(1))
                func_bytes = bytearray(tmp_bytes)
                fpw.write('"')
                if first:
                    first = False
                else:
                    fpw.write('.')
                for j in range(20):
                    fpw.write(format(func_bytes[j], "0>2x"))
                fpw.write("\":\nvoid ")
                output = real_names[i].replace("(","("+FUNCTION_NAME+" *this<ecx>, ").replace(", void","").replace(", )", "").replace(")", "")
                broken = output.split("(")
                args = broken[1].split(",")
                if len(args) > 1:
                    args[0] = args[0] + ", "
                    for i, arg in enumerate(args[1:]):
                        args[i + 1] = arg.strip() + " unk" + str(i)
                        if i != len(args) - 2:
                            args[i + 1] = args[i + 1] + ", "
                        else:
                            args[i + 1] = args[i + 1] + ")"
                else:
                    args[0] = args[0] + ")"
                output = broken[0] + "(" + "".join(args)
                fpw.write(output + ";\n")
    print "Done"
main()