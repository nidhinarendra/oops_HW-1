#!/usr/bin/python

import os
import re

from subprocess import call

sbt_pattern1 = re.compile(".*cpp$")
sbt_pattern2 = re.compile(".*cc$")

for dir_entry in os.listdir('.'):
    if (sbt_pattern1.match(dir_entry) or sbt_pattern2.match(dir_entry)):
        print ("processing file:" + dir_entry);
        result = call(["g++", "-std=c++11","-o", dir_entry + ".exe", dir_entry]);
        if (result == 0):	
            grade = 10
	
            # Test 1 expected 3900
            print ("file:" + dir_entry + "compiled successfully!, result =" + str(result) );
            exe_file = "./" + dir_entry + ".exe";
            print ("processing exe file: " + exe_file);
            f = open(exe_file + "test1.out",'w')
            lf = open(exe_file + "test1.err",'w')
            result = call([exe_file, "data1_pos.txt"], stdout=f, stderr=lf);
            lf.close();
            f.close()

            success = 0
	    print("Test1: All positive numbers\n")
            if (result == 0):
                print ("test1 exe file: " + exe_file +"returned 0, success!");
                f = open(exe_file + "test1.out",'r')
                t1_pattern = re.compile("(\s|\w|:|=|\")*3900(\s|\")*")
		t2_pattern = re.compile("(\s|\w|:|=|\")*3900(\s|\")*")
                for line in f:
                    if (t1_pattern.match(line)):
                        print ("test1 Naive test exe file SUCCEDED!: " + exe_file + "output=" + line);
                        success = 1
                        grade += 5
                    else:
		    	print ("test1 for Naive failed test Expected:3900, your output:"+ line)
		    nextline=f.next()
		    if (t2_pattern.match(nextline)):
                        print ("test1 for Divide & Conquer exe file SUCCEDED!: " + exe_file + "output=" + nextline);
                        success = 1
                        grade += 5
                        break;
		    else:
			print("test1 for Divide & conquer failed test Expected: 3900, your output:"+ nextline)
			break;
                f.close()

            if (result != 0 or success == 0):
                print ("test1 exe file: " + exe_file +"returned " + str(result) + ", failure!");
                print ("test1 exe file expected output = >>>>>3900<<<<<");
                print ("test1 exe file: " + exe_file +"STDOUT= ");
                if (os.path.isfile(exe_file + "test1.out")):
                    f = open(exe_file + "test1.out",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test1 exe file: " + exe_file +"NO STDOUT!!");                    
                print ("test1 exe file: " + exe_file +"STDERR= ");
                if (os.path.isfile(exe_file + "test1.err")):                
                    f = open(exe_file + "test1.err",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test1 exe file: " + exe_file +"NO STDERR!!");                                        


            # Test 2 579

            f = open(exe_file + "test2.out",'w')
            lf = open(exe_file + "test2.err",'w')
            result = call([exe_file, "data2_mix.txt"], stdout=f, stderr=lf);
            lf.close()
            f.close()

            success = 0
            print("Test2: Mix of positive and Negative nos\n")
            if (result == 0):
                print ("test2 exe file: " + exe_file +"returned 0!");
                f = open(exe_file + "test2.out",'r')
                t1_pattern = re.compile("(\s|\w|:|=|\")*579(\s|\")*")
		t2_pattern = re.compile("(\s|\w|:|=|\")*579(\s|\")*")
                for line in f:
                    if (t1_pattern.match(line)):
                        print ("test2 Naive test for exe file SUCCEDED!: " + exe_file + "output=" + line);
                        success = 1
                        grade += 10
                    else:   
		    	print ("test2 Naive failed test Expected:579, your output:"+ line)
		    nextline=f.next()
		    if (t2_pattern.match(nextline)):
                        print ("test2 for Divide & Conquer exe file SUCCEDED!: " + exe_file + "output=" + nextline);
                        success = 1
                        grade += 10
                        break;
		    else:	    
			print("test2 for Divide & Conquer failed test Expected:579, your output:"+ nextline)
			break;
                f.close()

            if (result != 0 or success == 0):
                print ("test2 exe file: " + exe_file +"returned " + str(result) + ", failure!");
                print ("test2 exe file expected output = >>>>>579<<<<<");
                print ("test2 exe file: " + exe_file +"STDOUT= ");
                if (os.path.isfile(exe_file + "test2.out")):
                    f = open(exe_file + "test2.out",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test2 exe file: " + exe_file +"NO STDOUT!!"); 
                print ("test2 exe file: " + exe_file +"STDERR= ");
                if (os.path.isfile(exe_file + "test2.err")):   
                    f = open(exe_file + "test2.err",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test2 exe file: " + exe_file +"NO STDERR!!");
            
            # Test 3 expected 69

            f = open(exe_file + "test3.out",'w')            
            lf = open(exe_file + "test3.err",'w')
            result = call([exe_file, "data3_space.txt"], stdout=f, stderr=lf);
            lf.close();            
            f.close()

            success = 0
            print("Test3: Positive numbers with spaces in between\n")
            if (result == 0):
                print ("test3 exe file: " + exe_file +"returned 0!");
                f = open(exe_file + "test3.out",'r')
                t1_pattern = re.compile("(\s|\w|:|=|\")*69(\s|\")*")
		t2_pattern = re.compile("(\s|\w|:|=|\")*69(\s|\")*")
                for line in f:
                    if (t1_pattern.match(line)):
                        print ("test3 Naive test for exe file SUCCEDED!: " + exe_file + "output=" + line);
                        success = 1
                        grade += 5
                    else:   
		    	print ("test3 Naive failed test Expected:69, your output:"+ line)
		    nextline=f.next()
		    if (t2_pattern.match(nextline)):
                        print ("test3 for Divide & Conquer exe file SUCCEDED!: " + exe_file + "output=" + nextline);
                        success = 1
                        grade += 5
                        break;
		    else:
			print("test3 for Divide & Conquer failed test Expected:69, your output:"+ nextline)
			break
                f.close()

            if (result != 0 or success == 0):
                print ("test3 exe file: " + exe_file +"returned " + str(result) + ", failure!");
                print ("test3 exe file expected output = >>>>>69<<<<<");
                print ("test3 exe file: " + exe_file +"STDOUT= ");
                if (os.path.isfile(exe_file + "test3.out")):
                    f = open(exe_file + "test3.out",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test3 exe file: " + exe_file +"NO STDOUT!!");   
                print ("test3 exe file: " + exe_file +"STDERR= ");
                if (os.path.isfile(exe_file + "test3.err")):
                    f = open(exe_file + "test3.err",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test3 exe file: " + exe_file +"NO STDERR!!");
            
            # Test 4 expected error

            f = open(exe_file + "test4.out",'w')            
            lf = open(exe_file + "test4.err",'w')
            result = call([exe_file, "data4_char.txt"], stdout=f, stderr=lf);
            lf.close();
            f.close()

            success = 0
            print("Test4: Characters and Symbols with integers\n")
            #if (result != 0):
               # print ("test4 exe file: " + exe_file +"returned non 0!");
   	    if (os.path.isfile(exe_file + "test4.err")and os.path.getsize(exe_file + "test4.err") > 0):
		    f = open(exe_file + "test4.err",'r')
                    for line in f:
                        print ("test4 for exe file SUCCEDED!: " + exe_file + "output=" + line);
			break;
		    success = 1
	            grade += 20
                    f.close()
            else:
                  print ("test4 exe file Failed: " + exe_file +"NO STDERR!!");
	       	 
		# Test 5 expected -2

            f = open(exe_file + "test5.out",'w')            
            lf = open(exe_file + "test5.err",'w')
            result = call([exe_file, "data5_neg.txt"], stdout=f, stderr=lf);
            lf.close();
            f.close()

            success = 0
            print("Test5: All negative numbers\n")
            if (result == 0):
                print ("test5 exe file: " + exe_file +"returned 0!");
                f = open(exe_file + "test5.out",'r')
                t1_pattern = re.compile("(\s|\w|:|=|\")*-2(\s|\")*")
		t2_pattern = re.compile("(\s|\w|:|=|\")*-2(\s|\")*")
                for line in f:
                    if (t1_pattern.match(line)):
                        print ("test5 Naive test for exe file SUCCEDED!: " + exe_file + "output=" + line);
                        success = 1
                        grade += 5
                    else: 
		    	print ("test5 Naive failed test, Expected:-2, your output:"+ line)
		    nextline=f.next()
		    if (t2_pattern.match(nextline)):
                        print ("test5 for Divide & Conquer exe file SUCCEDED!: " + exe_file + "output=" + nextline);
                        success = 1
                        grade += 5
                        break;
		    else:
			print("test5 for Divide & Conquer failed test,Expected:-2, your output:"+ nextline)
			break;
                f.close()

            if (result != 0 or success == 0):
                print ("test5 exe file: " + exe_file +"returned " + str(result) + ", failure!");
                print ("test5 exe file expected output = >>>>>-2<<<<<");
                print ("test5 exe file: " + exe_file +"STDOUT= ");
                if (os.path.isfile(exe_file + "test5.out")):
                    f = open(exe_file + "test5.out",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test5 exe file: " + exe_file +"NO STDOUT!!");
                print ("test5 exe file: " + exe_file +"STDERR= ");
                if (os.path.isfile(exe_file + "test5.err")):
                    f = open(exe_file + "test5.err",'r')
                    for line in f:
                        print (line);
                    f.close()
                else:
                    print ("test5 exe file: " + exe_file +"NO STDERR!!");  
	# Test 6 expected error

            f = open(exe_file + "test6.out",'w')            
            lf = open(exe_file + "test6.err",'w')
            result = call([exe_file, "data_abc.txt"], stdout=f, stderr=lf);
            lf.close();
            f.close()

            success = 0
            print("Test6: Incorrect file name given i.e File does not exist\n")
            if (os.path.isfile(exe_file + "test6.err")and os.path.getsize(exe_file + "test6.err") > 0):
                    f = open(exe_file + "test6.err",'r')
                    for line in f:
                        print ("test6 for exe file SUCCEDED!: " + exe_file + "output=" + line);
			break;
		    success = 1
	            grade += 10
                    f.close()
                
	    else:	
		print ("test6 exe file FAILED: " + exe_file +"NO STDERR or returned 0!!"); 
			
	    # Test 7 expected both algos

            f = open(exe_file + "test7.out",'w')            
            lf = open(exe_file + "test7.err",'w')
            result = call([exe_file, "data7_both.txt"], stdout=f, stderr=lf);
            lf.close();
            f.close()

            success = 0
            print("Test7: Test if Both Algos used\n")
            if (result == 0):
                print ("test7 exe file: " + exe_file +"returned 0!");
   
            if(os.path.isfile(exe_file + "test7.out")and os.path.getsize(exe_file + "test7.out") > 0):
		
		    with open(exe_file + "test7.out",'r') as f:
    		     	seen = set()
    			for line in f:
        			line_lower = line.lower()
        			if line_lower in seen:
            				print ("test7 for checking if both algos used Failed!: " + exe_file + "output=" + line);
					success=0
        			else:
            				seen.add(line_lower)
					success = 1
					print ("test7 for checking if both algos used SUCCEDED!: " + exe_file + "output=" + line);
	            			
		    	
                    f.close()
	    if(success==1):
		grade += 10
		
	    else:
                  print ("test7 exe file Failed: " + exe_file +"Not used both algos"); 							

            print ("exe file: " + exe_file + "==>FINAL GRADE = " + str(grade));
      
            print ("\n\n");
