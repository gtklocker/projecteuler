from os import listdir, getcwd
from subprocess import call

files = [ i for i in listdir( getcwd() ) if i[ 0:1+1 ] == 'pe' ]

def zerofill( n ):
    if n < 10:
        return '000'
    if n < 100:
        return '00'
    if n < 1000:
        return '0'
for f in files:
    probn = filter( lambda x: x.isdigit(), f )
    newf = zerofill( int( probn ) ) + str( probn ) + f[ f.index( '.' ): ]
    if call( [ "git", "mv", f, newf ] ):
        call( [ "mv", f, newf ] )
