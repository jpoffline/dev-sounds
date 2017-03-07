export CLICOLOR=1
export LSCOLORS=ExFxCxDxBxegedabagacad

#PS1="jap\w: "

 
export PATH=$PATH:/usr/local

alias loginpi="ssh -X pi@192.168.0.55"

alias gp=gnuplot
alias python=python2.7

alias emacs='open -a /Applications/Emacs.app $1'


alias login_nottm='ssh -Y ppzjap@pppzjp.physics.nottingham.ac.uk'


##
# Your previous /Users/jap/.bash_profile file was backed up as /Users/jap/.bash_profile.macports-saved_2015-01-12_at_15:04:29
##

# MacPorts Installer addition on 2015-01-12_at_15:04:29: adding an appropriate PATH variable for use with MacPorts.
export PATH="/opt/local/bin:/opt/local/sbin:$PATH"
# Finished adapting your PATH environment variable for use with MacPorts.

# A pretty git-log printer
alias git-log="git log --graph --abbrev-commit --decorate --format=format:'%C(bold blue)%h%C(reset) - %C(bold green)(%ar)%C(reset) %C(white)%s%C(reset) %C(dim white)- %an%C(reset)%C(bold yellow)%d%C(reset)' --all"
export PATH=$PATH:/bin/bkup
eval $(/usr/libexec/path_helper -s)




parse_git_branch() {
    git branch 2> /dev/null | sed -e '/^[^*]/d' -e 's/* \(.*\)/ (\1)/'
}

export PS1='\[$(tput setaf 7)\]\u@:\[$(tput setaf 4)\]\w\[$(tput setaf 1)\]$(parse_git_branch)\[$(tput sgr0)\] $ '

