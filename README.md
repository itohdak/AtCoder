# Sources for AtCoder programming contests
## Links
- [AtCoder Home](https://atcoder.jp/?lang=ja "AtCoder Home")
- [AtCoder Problems](https://kenkoooo.com/atcoder/?user=itohdak&rivals=&kind=category#/table/itohdak "AtCoder Problems")
- [itohdak Profile](https://atcoder.jp/user/itohdak "itohdak Profile")
- [test cases](https://www.dropbox.com/sh/arnpe0ef5wds8cv/AAAk_SECQ2Nc6SVGii3rHX6Fa?dl=0 "test cases")

## Quick Usage
```
$ git clone https://github.com/itohdak/AtCoder.git
$ cd AtCoder
$ source setup.sh # this will overwrite ~/.bashrc to define function "mkdir_atcoder"
$ mkdir_atcoder [folder_name]
# you can see a new folder named [folder_name] which includes sample cpp files
```
## Utils
### Bash Codes
```
# remove comment outs and local-depended include line
function cat_atcoder () {
    cat $1 | grep -v "^ *//" | grep -v "#include \"/home/itohdak/AtCoder/000/print.hpp\""
}

# copy to clipboard
alias pbcopy='xsel --clipboard --input'
```
### Sample Usage
```
$ cat_atcoder A.cpp | pbcopy

# You can paste the copied codes with Ctrl-V
```
