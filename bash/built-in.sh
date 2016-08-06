type cd #shell built-in or OS?
type id

type -t cd #displays only built-in
type -t id #file

type -tp cd #+path
type -tp id

type -a pwd #lists all available versions

#discouraged, mostly used for testing and porting older scripts to bash env
#a well-structured script shouldn't have to rely on them- you should know what environment your script is running in or make it independent
builtin pwd #use built-in

command pwd #use command


