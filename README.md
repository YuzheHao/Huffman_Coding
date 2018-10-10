# Huffman_Coding  
This is a curriculum design project of Information Theory and Coding when I was a junior in collage.  
At that time, other people in the group, basically, using MATLAB to make such a design due to the existed functions package. For reviewing the knowledge of C++, I forced myself to use C++, that's why I wrote this.  
<details>
  <summary>If you don't know how to read Chinese o_o </summary>
  <p>代码中的注释全部是中文，这可能会给你带来麻烦；如果你需要英文的注释，请联系我，我会试着抽时间写一下英文注释</p>
</details>  

### What are these?  
There are three files, achieving binary and ternary Huffman_Coding as their name. The "combined" mean putting two former program into one, and you can choose which radix to be used for the program.  
### "Over-simple" combination
As you can see at the beginning of combined program, I defined two structs for two parts of code. I simply linked two programs into one, and used a flag <code>sys</code>to choose which part of code to run. The struct node used to complete H-coding have some differences, that's why I defined two structs for two parts of code, as you can see at the beginning of combined program. At first, I try to use one struct for two different processes, but almost every parts of coding process need a flag to tell whether it's for binary or ternary, and the program became a mess. So, I use this simple way. ~~(despite the code became longer and longer)~~
### If you could help me:
Obviously, this program can be better. If you have some advices, that would be very nice and I would be very glad to hear them.
