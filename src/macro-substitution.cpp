#ifdef __RESHARPER__

#define AT(index, seqs) FIRST(TAKE_ ## index seqs)

#define TAKE_0(x) x,
#define TAKE_1(x) TAKE_0
#define TAKE_2(x) TAKE_1
#define TAKE_3(x) TAKE_2
#define TAKE_4(x) TAKE_3
#define TAKE_5(x) TAKE_4
#define TAKE_6(x) TAKE_5

#define FIRST2(x, y) x
#define FIRST(xy) FIRST2(xy)

AT(3, (a)(b)(c)(d)(e)(f))

#endif