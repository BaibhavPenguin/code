#ifndef command_h
#define command_h

#define no_op 0        //--done
#define error_op 1     //--done


#define cadd 96  //add      --done
#define csub 16  //sub      --done
#define cdiv 208   //div    --done
#define cmul 194 //mul      --done
#define cclr 112  //clear           --done
#define cand 196      //and         --done
#define corr 184            //or    --done
     
#define cxor 216           //xor    --done
#define cmod 126        //mod       --done
#define csleep 150      //sleep     --done
#define crst 170        //reset     --done


#define cerase 23   //erase   --done (message left)

#define cmove 181   //.move

#define hwport 100  //.hwport   --done
#define cdefine 37  // .define  --done
#define cprog 117   // prog     --done
#define crun 184    // run      --done
#define cexit 101   // /prog    --done


#define cprint 132  //.print    --done

#define cdecrement 197  //dec   --done
#define cincrement 19   //inc   --done 
#define cnot 242      //not     --done

#define cend 166    // exit     --done
#define cparse 195  // .parse   --done
#define cassign 176 // .assign  --done

#define cdelete 65  // .delete
#define cload 250   //.load --done 
#define ccopy 125    //.copy    --done
#define cif 168     // .if   --done    
#define cloop 146   // .loop    

#define cgoto 59    // .goto
#define cblock 21   // .block


#define c_enter '\r' //On Pressing Enter Key

#define crshift 212 // rshift   --done
#define clshift 20  // lshift   --done

#define cfi 141      // .fi     --done
#define endifl 30
#define endifh 30
#define fcheckfi 225
#define scheckfi 255



// cls handling done by clear_terminal system routine.
#define cbreak 137  //.break

#define cpool 46    // .pool
#define endloopl 64
#define endlooph 46
#define fcheckloop 64
#define scheckloop 46


#endif  //command_h

