
# ft_printf

Recreation of `printf` function in C standard input/output library


## Getting Started

### Installation
```bash
git clone https://github.com/arkim42/ft_printf.git
make
```
### Usage
`int	ft_printf(const char *format, ...)`

## Options

| specifier | description|
|:--------:|------------|
| `c` | Character |
| `s` | String of characters |
| `p` | Pointer address |
| `d` or `i` | Signed decimal integer |
| `o` | Unsigned octal |
| `u` | Unsigned decimal integer |
| `x` | Unsigned hexadecimal integer |
| `X` | Unsigned hexadecimal integer (uppercase) |
| `f` | Decimal floating point, lowercase |
| `e` | Scientific notation (mantissa/exponent), lowercase |
| `E` | Scientific notation (mantissa/exponent), uppercase |
| `b` | Binary integer |
    
| specifier \ <br> length | `d`, `i` | `u`, `o`, `x`, `X` | `f` `e` `E` `b` | `c` | `s` | `p` |
|:-------:|:----------:|:--------------------:|:-----------------:|-----:|-----:|:-----:|
| *none* | int | unsigned int | double | int | char * | void *  |  |
|  `hh`  | signed char | unsigned char |  |  |  |  |  |
|  `h`   | short int | unsigned short int |  |  |  |  |  |
|  `l`   | long int | unsigned long int |  |  |  |  |  |
|  `ll`  | long long int | unsigned long long int |  |  |  |  |  |
|  `L`   | |  | long double |  |  |  |  |

| color | name|
|:-----:|:------:|
| ![](https://via.placeholder.com/15/000000/000000?text=+) | `{black}` |
| ![](https://via.placeholder.com/15/ff0000/000000?text=+) | `{red}` |
| ![](https://via.placeholder.com/15/00ff00/000000?text=+) | `{green}` |
| ![](https://via.placeholder.com/15/ffff00/000000?text=+) | `{yellow}` |
| ![](https://via.placeholder.com/15/0000ff/000000?text=+) | `{blue}` |
| ![](https://via.placeholder.com/15/ff00ff/000000?text=+) | `{magenta}` |
| ![](https://via.placeholder.com/15/00ffff/000000?text=+) | `{cyan}` |
| ![](https://via.placeholder.com/15/ffffff/000000?text=+) | `{white}` |

`{default}` : default color  
`{eoc}` : end of color
