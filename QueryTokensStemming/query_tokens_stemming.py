def token_stemming(tokens, suffixes):
    # Write your code here
    # To print results to the standard output you can use print
    # Example: print "Hello world!"
    suffixes.sort(key = len)
    for token in tokens:
        to_print = token
        for suffix in suffixes[::-1]:
            if token.endswith(suffix):
                to_print =  token[:-len(suffix)]
                break
        print to_print