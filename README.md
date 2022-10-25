# Record and replay using intel pt
Get trace using `sudo sptdecode -s ptout.sideband --pt ptout.0 -i -t | xed -F insn: -A -64 > dump.txt`
Get time using https://sourceware.org/gdb/onlinedocs/gdb/Process-Record-and-Replay.html
## Ref
1. https://godbolt.org/z/ExesaaE6n
2. https://easyperf.net/blog/2019/08/30/Intel-PT-part2
3. https://easyperf.net/blog/2019/09/06/Intel-PT-part3
