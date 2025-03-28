import argparse


def parse_args():
    parser = argparse.ArgumentParser(description='bldd - backward ldd tool')
    parser.add_argument('--libs', nargs='*', help='Shared libraries to track'
                        ' (e.g. libc.so.6)')
    parser.add_argument('--dir', default='.', help='Directory to scan'
                        ' (default: current)')
    parser.add_argument('--out', default='bldd_report.pdf', help='Output'
                        ' report filename')
    parser.add_argument('--format', default='pdf', choices=['txt', 'pdf'],
                        help='Output format (default: txt)')
    return parser.parse_args()
