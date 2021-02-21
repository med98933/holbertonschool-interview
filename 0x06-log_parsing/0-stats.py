#!/usr/bin/python3
"""
log parsing
"""
status_codes = {"200": 0, "301": 0,
                "400": 0, "401": 0,
                "403": 0, "404": 0,
                "405": 0, "500": 0}
c = 0
i = 0
a = ""
try:
    import sys
    for a in sys.stdin:
        word = a.split(" ")
        c = c + 1
        if len(word) >= 1:
            i = i + int(word[-1])
            if word[-2] in status_codes:
                status_codes[word[-2]] = status_codes[word[-2]] + 1

        if not c % 10:
            '''
            Prints file size
            '''
            print("File size:", i)
            for key in status_codes.keys():
                if status_codes[key] != 0:
                    print("%s: %d" % (key, status_codes[key]))
except KeyboardInterrupt:
    pass
else:
    print("file size:", i)
    for key in status_codes.keys():
        if status_codes[key] != 0:
            print("%s: %d" % (key, status_codes[key]))
