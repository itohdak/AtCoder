# Sources for AtCoder programming contests
## Links
- [AtCoder Home](https://atcoder.jp/?lang=ja "AtCoder Home")
- [AtCoder Problems](https://kenkoooo.com/atcoder/?user=itohdak&rivals=&kind=category#/table/itohdak "AtCoder Problems")
- [AtCoder Scores](https://atcoder-scores.herokuapp.com/graph?user=itohdak "AtCoder Scores")
- [itohdak Profile](https://atcoder.jp/user/itohdak "itohdak Profile")
- [test cases](https://www.dropbox.com/sh/arnpe0ef5wds8cv/AAAk_SECQ2Nc6SVGii3rHX6Fa?dl=0 "test cases")

## Quick Usage
```
$ git clone https://github.com/itohdak/AtCoder.git
$ cd AtCoder

# define function "mkdir_atcoder" in .bashrc
# add AtCoder/include to $CPATH in .bashrc
$ source setup.sh
$ exec bash

$ mkdir_atcoder [folder_name]
# you can see a new folder named [folder_name] which includes sample cpp files
```
## Utils
### pbcopy
You can copy your codes into the clipboard and paste them with Ctrl-V

#### How to enable
Add following lines to `~/.bashrc`
```
# copy to clipboard
alias pbcopy='xsel --clipboard --input'
```
Before using it, you may first need to install `xsel` with a following command
```
$ sudo apt install xsel
```
#### Sample Usage
```
$ cat A.cpp | pbcopy
# Ctrl-V on where you like to paste the codes
```

