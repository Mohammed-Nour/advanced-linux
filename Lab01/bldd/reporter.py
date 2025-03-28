

def generate_txt_report(results, out_file):
    with open(out_file, 'w') as f:
        for arch in results:
            f.write(f"---------- {arch} ----------\n")
            sorted_libs = sorted(results[arch].items(),
                                 key=lambda x: len(x[1]), reverse=True)
            for lib, paths in sorted_libs:
                f.write(f"{lib} ({len(paths)} execs)\n")
                for path in paths:
                    f.write(f"-> {path}\n")
            f.write("\n")
