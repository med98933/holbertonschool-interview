#!/usr/bin/python3
""" Parses Logs """
import sys

if __name__ == "__main__":

    status = {200: 0, 301: 0, 400: 0, 401: 0,
              403: 0, 404: 0, 405: 0, 500: 0}
    FileSize = [0]
    c = 1

    def print_stats():

        print('File size: {}'.format(FileSize[0]))

        for code in sorted(status.keys()):
            if status[code] != 0:
                print('{}: {}'.format(code, status[code]))

    def parse_stdin(line):

        try:
            line = line[:-1]
            word = line.split(' ')
            FileSize[0] = FileSize[0] + int(word[-1])
            sc = int(word[-2])
            if sc in status:
                status[sc] = status[sc] + 1
        except BaseException:
            pass

    try:
        for line in sys.stdin:
            parse_stdin(line)
            if c % 10 == 0:
                print_stats()
            c = c + 1
    except KeyboardInterrupt:
        print_stats()
        raise
    print_stats()
