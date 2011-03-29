version 6.0
if &cp | set nocp | endif
let s:cpo_save=&cpo
set cpo&vim
inoremap <C-Tab> 	
map! <S-Insert> <MiddleMouse>
inoremap <silent> <Plug>NERDCommenterInInsert  <BS>:call NERDComment(0, "insert")
imap <S-Tab> 
imap <F7> 
imap <F9>  :w 
snoremap <silent> 	 i<Right>=TriggerSnippet()
snoremap  b<BS>
snoremap % b<BS>%
snoremap ' b<BS>'
nmap ,cc <Plug>NERDCommenterComment
vmap ,cc <Plug>NERDCommenterComment
nmap ,c  <Plug>NERDCommenterToggle
vmap ,c  <Plug>NERDCommenterToggle
nmap ,cm <Plug>NERDCommenterMinimal
vmap ,cm <Plug>NERDCommenterMinimal
nmap ,cs <Plug>NERDCommenterSexy
vmap ,cs <Plug>NERDCommenterSexy
nmap ,ci <Plug>NERDCommenterInvert
vmap ,ci <Plug>NERDCommenterInvert
nmap ,cy <Plug>NERDCommenterYank
vmap ,cy <Plug>NERDCommenterYank
nmap ,cl <Plug>NERDCommenterAlignLeft
vmap ,cl <Plug>NERDCommenterAlignLeft
nmap ,cb <Plug>NERDCommenterAlignBoth
vmap ,cb <Plug>NERDCommenterAlignBoth
nmap ,cn <Plug>NERDCommenterNest
vmap ,cn <Plug>NERDCommenterNest
nmap ,cu <Plug>NERDCommenterUncomment
vmap ,cu <Plug>NERDCommenterUncomment
nmap ,c$ <Plug>NERDCommenterToEOL
vmap ,c$ <Plug>NERDCommenterToEOL
nmap ,cA <Plug>NERDCommenterAppend
vmap ,cA <Plug>NERDCommenterAppend
nmap ,ca <Plug>NERDCommenterAltDelims
map Q gq
snoremap U b<BS>U
vmap [% [%m'gv``
nmap \ih :IHS
nmap \is :IHS:A
nmap \ihn :IHN
map \mbe <Plug>MiniBufExplorer
map \mbc <Plug>CMiniBufExplorer
map \mbu <Plug>UMiniBufExplorer
map \mbt <Plug>TMiniBufExplorer
nmap <silent> \ca <Plug>VCSAdd
nmap <silent> \cc <Plug>VCSCommit
nmap <silent> \cD <Plug>VCSDelete
nmap <silent> \cd <Plug>VCSDiff
nmap <silent> \cG <Plug>VCSClearAndGotoOriginal
nmap <silent> \cg <Plug>VCSGotoOriginal
nmap <silent> \ci <Plug>VCSInfo
nmap <silent> \cL <Plug>VCSLock
nmap <silent> \cl <Plug>VCSLog
nmap <silent> \cN <Plug>VCSSplitAnnotate
nmap <silent> \cn <Plug>VCSAnnotate
nmap <silent> \cq <Plug>VCSRevert
nmap <silent> \cr <Plug>VCSReview
nmap <silent> \cs <Plug>VCSStatus
nmap <silent> \cU <Plug>VCSUnlock
nmap <silent> \cu <Plug>VCSUpdate
nmap <silent> \cv <Plug>VCSVimDiff
snoremap \ b<BS>\
vmap ]% ]%m'gv``
snoremap ^ b<BS>^
snoremap ` b<BS>`
vmap a% [%v]%
nmap gx <Plug>NetrwBrowseX
map <F11> :tabnext 
map <S-Insert> <MiddleMouse>
nnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(0, "norm")
vnoremap <silent> <Plug>NERDCommenterComment :call NERDComment(1, "norm")
nnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(0, "toggle")
vnoremap <silent> <Plug>NERDCommenterToggle :call NERDComment(1, "toggle")
nnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(0, "minimal")
vnoremap <silent> <Plug>NERDCommenterMinimal :call NERDComment(1, "minimal")
nnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(0, "sexy")
vnoremap <silent> <Plug>NERDCommenterSexy :call NERDComment(1, "sexy")
nnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(0, "invert")
vnoremap <silent> <Plug>NERDCommenterInvert :call NERDComment(1, "invert")
nmap <silent> <Plug>NERDCommenterYank :call NERDComment(0, "yank")
vmap <silent> <Plug>NERDCommenterYank :call NERDComment(1, "yank")
nnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(0, "alignLeft")
vnoremap <silent> <Plug>NERDCommenterAlignLeft :call NERDComment(1, "alignLeft")
nnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(0, "alignBoth")
vnoremap <silent> <Plug>NERDCommenterAlignBoth :call NERDComment(1, "alignBoth")
nnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(0, "nested")
vnoremap <silent> <Plug>NERDCommenterNest :call NERDComment(1, "nested")
nnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(0, "uncomment")
vnoremap <silent> <Plug>NERDCommenterUncomment :call NERDComment(1, "uncomment")
nnoremap <silent> <Plug>NERDCommenterToEOL :call NERDComment(0, "toEOL")
nmap <silent> <Plug>NERDCommenterAppend :call NERDComment(0, "append")
nnoremap <silent> <Plug>VCSAdd :VCSAdd
nnoremap <silent> <Plug>VCSAnnotate :VCSAnnotate
nnoremap <silent> <Plug>VCSCommit :VCSCommit
nnoremap <silent> <Plug>VCSDelete :VCSDelete
nnoremap <silent> <Plug>VCSDiff :VCSDiff
nnoremap <silent> <Plug>VCSGotoOriginal :VCSGotoOriginal
nnoremap <silent> <Plug>VCSClearAndGotoOriginal :VCSGotoOriginal!
nnoremap <silent> <Plug>VCSInfo :VCSInfo
nnoremap <silent> <Plug>VCSLock :VCSLock
nnoremap <silent> <Plug>VCSLog :VCSLog
nnoremap <silent> <Plug>VCSRevert :VCSRevert
nnoremap <silent> <Plug>VCSReview :VCSReview
nnoremap <silent> <Plug>VCSSplitAnnotate :VCSAnnotate!
nnoremap <silent> <Plug>VCSStatus :VCSStatus
nnoremap <silent> <Plug>VCSUnlock :VCSUnlock
nnoremap <silent> <Plug>VCSUpdate :VCSUpdate
nnoremap <silent> <Plug>VCSVimDiff :VCSVimDiff
snoremap <silent> <S-Tab> i<Right>=BackwardsSnippet()
snoremap <BS> b<BS>
snoremap <Right> a
snoremap <Left> bi
map <F8> :!gwj % >/dev/pts/6 2>&1 
nnoremap <silent> <Plug>NetrwBrowseX :call netrw#NetrwBrowseX(expand("<cWORD>"),0)
map <C-F12> :q! 
map <F12> :q 
map <F9> :w 
imap 	 
inoremap <silent> 	 =ShowAvailableSnips()
inoremap  u
imap \ih :IHS
imap \is :IHS:A
imap \ihn :IHN
let &cpo=s:cpo_save
unlet s:cpo_save
set background=dark
set backspace=indent,eol,start
set cindent
set fileencodings=ucs-bom,utf-8,default,latin1
set helplang=en
set history=50
set hlsearch
set incsearch
set nomodeline
set mouse=a
set ruler
set showcmd
set suffixes=.bak,~,.swp,.o,.info,.aux,.log,.dvi,.bbl,.blg,.brf,.cb,.ind,.idx,.ilg,.inx,.out,.toc
set termencoding=utf-8
set updatetime=1
" vim: set ft=vim :
