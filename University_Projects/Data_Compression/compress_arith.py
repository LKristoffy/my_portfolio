from math import log2, ceil
from random import random
from trees import *
from vl_codes import *
from itertools import groupby
from camzip import camzip
import arithmetic as arith


f = open('hamlet.txt', 'r')
hamlet = f.read()
f.close()


frequencies = dict([(key, len(list(group))) for key, group in groupby(sorted(hamlet))])
Nin = sum([frequencies[a] for a in frequencies])
p = dict([(a,frequencies[a]/Nin) for a in frequencies])
arith_encode = arith.encode(hamlet, p)


print(f'File length: {Nin}')

print(f'Length of binary sequence: {len(arith_encode)}')


hamlet_zipped = bits2bytes(arith_encode)
Nout = len(hamlet_zipped)
print(f'Length of compressed string: {Nout}')


H = lambda pr: -sum([pr[a]*log2(pr[a]) for a in pr])
print(f'Entropy: {H(p)}')

  

hamlet_unzipped = arith.decode(arith_encode, p, Nin)
print(f'Length of the unzipped file: {len(hamlet_unzipped)}')
print(f'Compression ratio (rateless): {Nout/Nin}')
print(f'Compression ratio (bits per byte): {8.0*Nout/Nin}')

print(''.join(hamlet_unzipped[:294]))
