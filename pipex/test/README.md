
    TEST 1
    This command should takes only the line that have the word PIPEX and redirect it to the oufile as uppercase.

    ./pipex test/infile "tr '[:lower:]' '[:upper:]'" "grep PIPEX" outfile && cat outfile
    
    < test/infile tr '[:lower:]' '[:upper:]' | grep PIPEX > outfile && cat outfile

    Result in outfile = PIPEX LALALA

    TEST 2
    This command should count the number of words in the infile and redirect it to the outfile.

    ./pipex test/infile1 "wc -w" "awk {print$1}" outfile && cat outfile
    
    < test/infile1 wc -w | awk '{print $1}' > outfile && cat outfile

    Result in outfile = 5

    TEST 3
    This command counts the number of unique lines in the infile and writes the count to outfile.

    ./pipex test/infile2 "uniq" "wc -l" outfile && cat outfile
    
    < test/infile2 uniq | wc -l > outfile && cat outfile

    Result in outfile = 6

    TEST 4
    This command sorts the lines in the infile, removes adjacent duplicates, and writes the result to the outfile.

    ./pipex test/infile2 "sort" "uniq" outfile && cat outfile
    
    < test/infile2 sort | uniq > outfile && cat outfile

    Result in outfile =
                            a
                            b
                            c
                            hola
                            tardes
                            wenas

    TEST 5
    This command counts the number of lines in tests/infile that contain the term "bro" (case-insensitive) and writes the count to outfile.

    ./pipex test/infile3 "grep -i bro" "wc -l" outfile && cat outfile
 
    < test/infile3 grep -i bro | wc -l > outfile && cat outfile

    Result in outfile = 3

    TEST 6
    This command should take only the name of the files on actual directory and redirect it to the outfile.

    ./pipex test/infile "ls -l" "awk {print\$9}" outfile
    < test/infile ls -l | awk '{print $9}' > outfile

    Result in outfile =
                            \n
                            lib
                            Makefile
                            obj
                            outfile
                            pipex
                            pipex.h
                            src
                            test



Error tests:

    ARGUMENTS TESTS

    ./pipex test/infile "sort" outfile
    ./pipex test/infile "sort" "uniq" "wc" outfile

    COMMANDS TESTS

    ./pipex test/infile "sor" "uni" outfile
    < test/infile sor | uni > outfile

    INFILE TESTS

    This should return non exiting file:
        ./pipex test/infile0 "uniq" "wc -l" outfile
        < test/infile0 uniq | wc -l > outfile

    This should return permission fail:
        chmod 000 infile
        ./pipex test/infile "grep -i PIPEX" "wc -l" outfile
        < test/infile grep -i PIPEX | wc -l > outfile

    OUTFILE TESTS

    chmod 000 outfile
    ./pipex test/infile "sort" "uniq" outfile
    < test/infile sort | uniq > outfile
