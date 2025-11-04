# Coco Conjecture

## Challenge
Solve the Collatz conjecture (3n+1 problem) 269 times in a row within 0.5 seconds per round.

## Solution
The Collatz conjecture follows these rules:
- If n is even: n = n/2
- If n is odd: n = 3n+1
- Count steps until n = 1

Implementation:
```python
def collatz_steps(n):
    steps = 0
    while n != 1:
        if n % 2 == 0:
            n = n // 2
        else:
            n = 3 * n + 1
        steps += 1
    return steps
```

The script connects to the server, extracts the number from each round, calculates the steps, and sends the answer. The algorithm is fast enough to handle 18-digit numbers well within the time limit.

## Flag
`citadel{k1ryu_c0c0_h4s_4_g0_4t_4n_uns0lv3d_m4th3m4t1cs_pr0bl3m}`


```

Round 17: 122767645398002059
Your answer: 450
Round 17 correct!

Round 18: 577002471260106261
Your answer: 527
Round 18 correct!

Round 19: 658516488747556344
Your answer: 592
Round 19 correct!

Round 20: 681337372639232351
Your answer: 380
Round 20 correct!

Round 21: 666856029356207528
Your answer: 473
Round 21 correct!

Round 22: 743200263548706593
Your answer: 375
Round 22 correct!

Round 23: 818365245526871450
Your answer: 432
Round 23 correct!

Round 24: 761682925325215979
Your answer: 225
Round 24 correct!

Round 25: 376908776498155906
Your answer: 317
Round 25 correct!

Round 26: 366732284111721752
Your answer: 405
Round 26 correct!

Round 27: 623335584713077864
Your answer: 553
Round 27 correct!

Round 28: 404584813156422855
Your answer: 418
Round 28 correct!

Round 29: 259996057106343731
Your answer: 358
Round 29 correct!

Round 30: 536777211182367668
Your answer: 328
Round 30 correct!

Round 31: 86755924685265946
Your answer: 558
Round 31 correct!

Round 32: 963829175927224758
Your answer: 326
Round 32 correct!

Round 33: 541934273323427727
Your answer: 377
Round 33 correct!

Round 34: 348323451269009916
Your answer: 454
Round 34 correct!

Round 35: 963007487040542285
Your answer: 308
Round 35 correct!

Round 36: 218922897044775216
Your answer: 580
Round 36 correct!

Round 37: 898343595653396764
Your answer: 352
Round 37 correct!

Round 38: 659836329570843490
Your answer: 349
Round 38 correct!

Round 39: 494860854706313010
Your answer: 377
Round 39 correct!

Round 40: 318269017419623960
Your answer: 335
Round 40 correct!

Round 41: 426449916700742571
Your answer: 493
Round 41 correct!

Round 42: 704445923867152296
Your answer: 331
Round 42 correct!

Round 43: 319141933047059224
Your answer: 366
Round 43 correct!

Round 44: 375607829613251207
Your answer: 255
Round 44 correct!

Round 45: 784341281688610514
Your answer: 556
Round 45 correct!

Round 46: 224394340162836570
Your answer: 642
Round 46 correct!

Round 47: 23825741095280269
Your answer: 445
Round 47 correct!

Round 48: 349474332830995712
Your answer: 304
Round 48 correct!

Round 49: 777084125734489020
Your answer: 282
Round 49 correct!

Round 50: 97084668347375674
Your answer: 677
Round 50 correct!

Round 51: 213120273773136077
Your answer: 368
Round 51 correct!

Round 52: 765989038988306913
Your answer: 419
Round 52 correct!

Round 53: 492799417738356487
Your answer: 263
Round 53 correct!

Round 54: 41065108369138937
Your answer: 619
Round 54 correct!

Round 55: 462325219350726361
Your answer: 607
Round 55 correct!

Round 56: 868718978046374322
Your answer: 719
Round 56 correct!

Round 57: 468528465065951390
Your answer: 302
Round 57 correct!

Round 58: 885182774370179075
Your answer: 613
Round 58 correct!

Round 59: 732642621934803549
Your answer: 331
Round 59 correct!

Round 60: 481122901685425730
Your answer: 364
Round 60 correct!

Round 61: 603038076812440188
Your answer: 535
Round 61 correct!

Round 62: 357819651938245607
Your answer: 330
Round 62 correct!

Round 63: 402236409045229923
Your answer: 493
Round 63 correct!

Round 64: 809675014687865927
Your answer: 318
Round 64 correct!

Round 65: 741786230987989424
Your answer: 574
Round 65 correct!

Round 66: 220985164661466830
Your answer: 518
Round 66 correct!

Round 67: 17862017642583623
Your answer: 261
Round 67 correct!

Round 68: 931398424945135933
Your answer: 303
Round 68 correct!

Round 69: 172601510643371347
Your answer: 440
Round 69 correct!

Round 70: 622595902478387062
Your answer: 504
Round 70 correct!

Round 71: 435140539556892137
Your answer: 687
Round 71 correct!

Round 72: 950224578917447377
Your answer: 502
Round 72 correct!

Round 73: 881110289683726094
Your answer: 321
Round 73 correct!

Round 74: 971425523626629345
Your answer: 458
Round 74 correct!

Round 75: 307883062812765314
Your answer: 335
Round 75 correct!

Round 76: 869108134667417553
Your answer: 489
Round 76 correct!

Round 77: 844117037672122742
Your answer: 569
Round 77 correct!

Round 78: 218927794471109844
Your answer: 319
Round 78 correct!

Round 79: 89050714019760503
Your answer: 863
Round 79 correct!

Round 80: 111832527203764584
Your answer: 530
Round 80 correct!

Round 81: 399892633412032023
Your answer: 480
Round 81 correct!

Round 82: 152547596990252174
Your answer: 489
Round 82 correct!

Round 83: 241789384759995402
Your answer: 469
Round 83 correct!

Round 84: 22367468123089360
Your answer: 326
Round 84 correct!

Round 85: 539762611577116529
Your answer: 377
Round 85 correct!

Round 86: 980095806539103700
Your answer: 210
Round 86 correct!

Round 87: 667819336449568484
Your answer: 455
Round 87 correct!

Round 88: 44865752664801307
Your answer: 420
Round 88 correct!

Round 89: 855253217061772993
Your answer: 631
Round 89 correct!

Round 90: 582532128270398363
Your answer: 385
Round 90 correct!

Round 91: 201711519113028130
Your answer: 448
Round 91 correct!

Round 92: 504640784574335954
Your answer: 514
Round 92 correct!

Round 93: 387454718943896952
Your answer: 374
Round 93 correct!

Round 94: 742337410286085373
Your answer: 424
Round 94 correct!

Round 95: 407748121413428946
Your answer: 400
Round 95 correct!

Round 96: 721072056701739103
Your answer: 517
Round 96 correct!

Round 97: 255909506867796125
Your answer: 557
Round 97 correct!

Round 98: 670829616065488461
Your answer: 349
Round 98 correct!

Round 99: 752398263590998822
Your answer: 375
Round 99 correct!

Round 100: 304081374940728463
Your answer: 451
Round 100 correct!

Round 101: 357809449403185503
Your answer: 255
Round 101 correct!

Round 102: 458328665859245827
Your answer: 395
Round 102 correct!

Round 103: 65927735636710334
Your answer: 418
Round 103 correct!

Round 104: 534107631971371129
Your answer: 488
Round 104 correct!

Round 105: 318418270894333410
Your answer: 273
Round 105 correct!

Round 106: 335522671820548522
Your answer: 379
Round 106 correct!

Round 107: 256781883171826052
Your answer: 451
Round 107 correct!

Round 108: 273489292804481753
Your answer: 327
Round 108 correct!

Round 109: 766880096993366189
Your answer: 357
Round 109 correct!

Round 110: 937131055595447798
Your answer: 440
Round 110 correct!

Round 111: 8873859844174363
Your answer: 384
Round 111 correct!

Round 112: 213920423834331548
Your answer: 567
Round 112 correct!

Round 113: 984317012340610717
Your answer: 533
Round 113 correct!

Round 114: 305649874304275579
Your answer: 353
Round 114 correct!

Round 115: 709054608550059965
Your answer: 393
Round 115 correct!

Round 116: 786562647234281176
Your answer: 419
Round 116 correct!

Round 117: 750907101139965768
Your answer: 481
Round 117 correct!

Round 118: 146253141202939436
Your answer: 326
Round 118 correct!

Round 119: 726784014587036467
Your answer: 605
Round 119 correct!

Round 120: 661998734159635405
Your answer: 380
Round 120 correct!

Round 121: 933220243623864890
Your answer: 595
Round 121 correct!

Round 122: 702936250079482667
Your answer: 367
Round 122 correct!

Round 123: 274160301352817633
Your answer: 433
Round 123 correct!

Round 124: 150470811706349701
Your answer: 321
Round 124 correct!

Round 125: 68617271117572311
Your answer: 206
Round 125 correct!

Round 126: 895171725079715970
Your answer: 401
Round 126 correct!

Round 127: 921033151807308167
Your answer: 419
Round 127 correct!

Round 128: 687703282765144209
Your answer: 486
Round 128 correct!

Round 129: 630436065631995517
Your answer: 416
Round 129 correct!

Round 130: 584197543355898473
Your answer: 509
Round 130 correct!

Round 131: 227627741962404894
Your answer: 487
Round 131 correct!

Round 132: 392311941413476269
Your answer: 418
Round 132 correct!

Round 133: 8956459885708767
Your answer: 379
Round 133 correct!

Round 134: 171645385427064038
Your answer: 471
Round 134 correct!

Round 135: 472302849101914726
Your answer: 364
Round 135 correct!

Round 136: 26452888533003875
Your answer: 471
Round 136 correct!

Round 137: 91857525442394425
Your answer: 421
Round 137 correct!

Round 138: 414052516788917405
Your answer: 431
Round 138 correct!

Round 139: 276896473293753556
Your answer: 190
Round 139 correct!

Round 140: 459958142160103589
Your answer: 532
Round 140 correct!

Round 141: 971017277589745398
Your answer: 564
Round 141 correct!

Round 142: 309713621790067173
Your answer: 428
Round 142 correct!

Round 143: 364676014566052922
Your answer: 405
Round 143 correct!

Round 144: 911734118061335217
Your answer: 476
Round 144 correct!

Round 145: 885849901899401782
Your answer: 432
Round 145 correct!

Round 146: 655034267707332160
Your answer: 274
Round 146 correct!

Round 147: 362472502664618423
Your answer: 436
Round 147 correct!

Round 148: 601095767308989805
Your answer: 266
Round 148 correct!

Round 149: 955854942839914239
Your answer: 378
Round 149 correct!

Round 150: 33088187220105121
Your answer: 417
Round 150 correct!

Round 151: 227545510269511470
Your answer: 412
Round 151 correct!

Round 152: 40537447807801193
Your answer: 500
Round 152 correct!

Round 153: 839428294263292674
Your answer: 499
Round 153 correct!

Round 154: 430108345574966085
Your answer: 537
Round 154 correct!

Round 155: 710857255183932682
Your answer: 331
Round 155 correct!

Round 156: 325882063667714113
Your answer: 578
Round 156 correct!

Round 157: 572965845521210437
Your answer: 403
Round 157 correct!

Round 158: 504997049902220031
Your answer: 576
Round 158 correct!

Round 159: 537630569031943215
Your answer: 594
Round 159 correct!

Round 160: 186552963664964814
Your answer: 466
Round 160 correct!

Round 161: 424736621261675967
Your answer: 462
Round 161 correct!

Round 162: 806587934580862933
Your answer: 251
Round 162 correct!

Round 163: 598469054148316006
Your answer: 323
Round 163 correct!

Round 164: 440897826575322227
Your answer: 462
Round 164 correct!

Round 165: 655546095798190619
Your answer: 318
Round 165 correct!

Round 166: 48591484911111902
Your answer: 322
Round 166 correct!

Round 167: 458957254978722224
Your answer: 444
Round 167 correct!

Round 168: 526751459269583520
Your answer: 315
Round 168 correct!

Round 169: 225525120884979489
Your answer: 319
Round 169 correct!

Round 170: 548747848648949843
Your answer: 390
Round 170 correct!

Round 171: 148813702063180846
Your answer: 414
Round 171 correct!

Round 172: 50752539764917993
Your answer: 596
Round 172 correct!

Round 173: 919318522556975310
Your answer: 471
Round 173 correct!

Round 174: 23132786108604211
Your answer: 393
Round 174 correct!

Round 175: 245358747592544011
Your answer: 438
Round 175 correct!

Round 176: 939293458041074815
Your answer: 396
Round 176 correct!

Round 177: 430316806111746520
Your answer: 573
Round 177 correct!

Round 178: 887539156873265508
Your answer: 427
Round 178 correct!

Round 179: 920051725746607519
Your answer: 458
Round 179 correct!

Round 180: 62964071182928199
Your answer: 467
Round 180 correct!

Round 181: 501536497515778856
Your answer: 532
Round 181 correct!

Round 182: 678110093246172674
Your answer: 548
Round 182 correct!

Round 183: 862572418268568762
Your answer: 308
Round 183 correct!

Round 184: 835798106659752281
Your answer: 463
Round 184 correct!

Round 185: 665081891764625772
Your answer: 504
Round 185 correct!

Round 186: 191211114300014417
Your answer: 448
Round 186 correct!

Round 187: 346176760295275412
Your answer: 415
Round 187 correct!

Round 188: 316327634001269752
Your answer: 578
Round 188 correct!

Round 189: 856091967161343906
Your answer: 538
Round 189 correct!

Round 190: 690869595545680601
Your answer: 442
Round 190 correct!

Round 191: 256754259899702329
Your answer: 495
Round 191 correct!

Round 192: 520934980413224892
Your answer: 377
Round 192 correct!

Round 193: 96256922568505262
Your answer: 403
Round 193 correct!

Round 194: 773881658428736644
Your answer: 450
Round 194 correct!

Round 195: 729304242208435149
Your answer: 437
Round 195 correct!

Round 196: 546595783800497902
Your answer: 403
Round 196 correct!

Round 197: 594175497952192606
Your answer: 465
Round 197 correct!

Round 198: 252107807681151442
Your answer: 650
Round 198 correct!

Round 199: 258399366192383962
Your answer: 464
Round 199 correct!

Round 200: 10287818436921142
Your answer: 317
Round 200 correct!

Round 201: 865571199044719910
Your answer: 370
Round 201 correct!

Round 202: 276883155270087685
Your answer: 402
Round 202 correct!

Round 203: 372629911102379210
Your answer: 312
Round 203 correct!

Round 204: 766770977050621441
Your answer: 450
Round 204 correct!

Round 205: 172409362486052840
Your answer: 714
Round 205 correct!

Round 206: 990716137822829173
Your answer: 440
Round 206 correct!

Round 207: 921631033666738917
Your answer: 414
Round 207 correct!

Round 208: 663171434473339281
Your answer: 486
Round 208 correct!

Round 209: 875665177936833085
Your answer: 414
Round 209 correct!

Round 210: 154583881406758175
Your answer: 440
Round 210 correct!

Round 211: 555950562680625459
Your answer: 403
Round 211 correct!

Round 212: 844072998479999137
Your answer: 781
Round 212 correct!

Round 213: 912316869245242898
Your answer: 489
Round 213 correct!

Round 214: 371319735094485818
Your answer: 343
Round 214 correct!

Round 215: 817476580756796844
Your answer: 432
Round 215 correct!

Round 216: 411750447487157746
Your answer: 475
Round 216 correct!

Round 217: 243055640520810870
Your answer: 394
Round 217 correct!

Round 218: 327965821982555508
Your answer: 428
Round 218 correct!

Round 219: 299695345670424593
Your answer: 415
Round 219 correct!

Round 220: 402563093450856452
Your answer: 493
Round 220 correct!

Round 221: 769783330188258878
Your answer: 442
Round 221 correct!

Round 222: 643401671456380925
Your answer: 380
Round 222 correct!

Round 223: 110596019990809914
Your answer: 248
Round 223 correct!

Round 224: 83061345446596698
Your answer: 545
Round 224 correct!

Round 225: 614493156183507404
Your answer: 535
Round 225 correct!

Round 226: 953516073193280984
Your answer: 564
Round 226 correct!

Round 227: 822531782664968671
Your answer: 569
Round 227 correct!

Round 228: 399999922002105076
Your answer: 343
Round 228 correct!

Round 229: 940227601243635634
Your answer: 352
Round 229 correct!

Round 230: 120028235250154587
Your answer: 300
Round 230 correct!

Round 231: 816030633713430135
Your answer: 432
Round 231 correct!

Round 232: 662851060402351428
Your answer: 380
Round 232 correct!

Round 233: 211279033957109502
Your answer: 580
Round 233 correct!

Round 234: 270402812076028616
Your answer: 319
Round 234 correct!

Round 235: 321550521885179921
Your answer: 278
Round 235 correct!

Round 236: 177127631988321131
Your answer: 404
Round 236 correct!

Round 237: 363564267067872566
Your answer: 343
Round 237 correct!

Round 238: 138325461505099844
Your answer: 339
Round 238 correct!

Round 239: 504599266816659903
Your answer: 346
Round 239 correct!

Round 240: 867563489410317013
Your answer: 339
Round 240 correct!

Round 241: 22512414005387932
Your answer: 481
Round 241 correct!

Round 242: 687378146246673728
Your answer: 243
Round 242 correct!

Round 243: 96790775654432940
Your answer: 354
Round 243 correct!

Round 244: 207331110387472713
Your answer: 306
Round 244 correct!

Round 245: 62762059711209557
Your answer: 392
Round 245 correct!

Round 246: 414430619672364923
Your answer: 431
Round 246 correct!

Round 247: 614280283537406452
Your answer: 336
Round 247 correct!

Round 248: 283070028455420387
Your answer: 477
Round 248 correct!

Round 249: 438446825104367132
Your answer: 405
Round 249 correct!

Round 250: 687812875308389296
Your answer: 318
Round 250 correct!

Round 251: 492223466332194833
Your answer: 408
Round 251 correct!

Round 252: 164809955580756942
Your answer: 321
Round 252 correct!

Round 253: 536687125283910141
Your answer: 408
Round 253 correct!

Round 254: 66211805712718129
Your answer: 418
Round 254 correct!

Round 255: 428298790123234410
Your answer: 307
Round 255 correct!

Round 256: 488792664256565470
Your answer: 620
Round 256 correct!

Round 257: 861808576767571229
Your answer: 357
Round 257 correct!

Round 258: 6529318137301619
Your answer: 425
Round 258 correct!

Round 259: 468343061596461532
Your answer: 488
Round 259 correct!

Round 260: 224451113943971312
Your answer: 479
Round 260 correct!

Round 261: 404057392041684452
Your answer: 294
Round 261 correct!

Round 262: 900783001560257458
Your answer: 401
Round 262 correct!

Round 263: 48399264854336398
Your answer: 433
Round 263 correct!

Round 264: 726827572051403485
Your answer: 318
Round 264 correct!

Round 265: 743925883285764396
Your answer: 313
Round 265 correct!

Round 266: 751324344495223958
Your answer: 406
Round 266 correct!

Round 267: 492565971606788172
Your answer: 470
Round 267 correct!

Round 268: 579930850896020132
Your answer: 465
Round 268 correct!

Round 269: 135005919826023536
Your answer: 600
Round 269 correct!

Well done! Our dragon CEO is proud. Here is your flag: citadel{k1ryu_c0c0_h4s_4_g0_4t_4n_uns0lv3d_m4th3m4t1cs_pr0bl3m}      

PS C:\Citadel_CTF_Writeups\Coco_Conjecture> 
```