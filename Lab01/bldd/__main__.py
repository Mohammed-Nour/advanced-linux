from .cli import parse_args
from .scanner import scan_directory
from .reporter import generate_txt_report


def main():
    args = parse_args()
    results = scan_directory(args.dir, args.libs)
    generate_txt_report(results, args.out)


if __name__ == "__main__":
    main()
