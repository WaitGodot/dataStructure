set number
set syntax=on
set completeopt=preview,menu
filetype plugin on
set cursorline
set magic
set tabstop=4
set softtabstop=4
set shiftwidth=4
set history=100
set hlsearch
set incsearch
set enc=utf-8
set fencs=utf-8,ucs-bom,shift-jis,gb18030,gbk,gb2312,cp936
set mouse=a
set showmatch
set smartindent

map <C-F2> : vert diffsplit
map <F3> : tabnew(CR);
map <C-F3> : tabnew.(CR);

:inoremap ( ()<ESC>i
:inoremap ) <c-r>=ClosePair(')')<CR>
:inoremap { {<CR>}<ESC>O
:inoremap } <c-r>=ClosePair('}')<CR>
:inoremap [ []<ESC>i
:inoremap ] <c-r>=ClosePair(']')<CR>
:inoremap " ""<ESC>i
:inoremap ' ''<ESC>i
function! ClosePair(char)
    if getline('.')[col('.') - 1] == a:char
        return "\<Right>"
    else
        return a:char
    endif
endfunction
filetype plugin indent on 
set completeopt=longest,menu
