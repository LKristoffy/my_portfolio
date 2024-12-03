from math import log2, ceil
from random import random
from trees import *
from vl_codes import *
from itertools import groupby
from camzip import camzip


f = open('hamlet.txt', 'r')
hamlet = f.read()
f.close()


frequencies = dict([(key, len(list(group))) for key, group in groupby(sorted(hamlet))])
Nin = sum([frequencies[a] for a in frequencies])
p = dict([(a,frequencies[a]/Nin) for a in frequencies])
c = huffman(p)
tree = xtree2newick(c)
print(p)
print(tree)
print(xtree2code(c))
print(f'File length: {Nin}')
print(type(hamlet))
code = xtree2code(c)
hamlet_sf = vl_encode(hamlet,code);
print(f'Length of binary sequence: {len(hamlet_sf)}')

'''
x = bits2bytes([0,1])
print([format(a, '08b') for a in x])
y = bytes2bits(x)
print(f'The original bits are: {y}')'''

hamlet_zipped = bits2bytes(hamlet_sf)
Nout = len(hamlet_zipped)
print(f'Length of compressed string: {Nout}')


H = lambda pr: -sum([pr[a]*log2(pr[a]) for a in pr])
print(f'Entropy: {H(p)}')

  

hamlet_unzipped = vl_decode(hamlet_sf,c)
print(f'Length of the unzipped file: {len(hamlet_unzipped)}')
print(f'Compression ratio (rateless): {Nout/Nin}')
print(f'Compression ratio (bits per byte): {8.0*Nout/Nin}')

print(''.join(hamlet_unzipped[:294]))

hamlet_huf = vl_encode(hamlet, code)
hamlet_corrupted = hamlet_huf.copy()
hamlet_corrupted[400] ^= 1
hamlet_decoded = vl_decode(hamlet_corrupted, c)
print(''.join(hamlet_decoded[:297]))