# Sine Wave Integer Table
Write a program to create an integer table for one period of sine wave.
Content of this table can be use as LUT values in building NCO!

User inputs:
- Number of samples
- Number of bits for values in table (for example `num_bits=10` values should be in range of `-511` to `+511`)

Output:
Print content of table


## Examples

Create a table with 8 entries and size of 10bit

```
    $ ./sintable 8 10
        0
        361
        511
        361
        0
        -361
        -511
        -361
```

```
    $ ./sintable 4 2
        0
        1
        0
        -1
```


## Option: Create Sine/Cosine Samples
Create IQ samples by printing sine and cosine samples. Enable this mode if user send `c` as third argument:
```
$ ./sintable 4 8 c
0    127
127  0
0    -127
-127 0
```
**NOTE:** Aligned printing for the second column is optional!

## Option: Check user input validity and print usage
Check if all user inputs are valid and provide proper usage command
in case of invalid arguments.
