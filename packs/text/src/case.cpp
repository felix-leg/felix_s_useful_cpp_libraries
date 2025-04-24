/*
This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <https://unlicense.org>

*/
#include "case.hpp"

namespace unicode {
	
	char32_t to_upper(char32_t from_c) noexcept {
		if( from_c >= 97 && from_c < 123 ) { return from_c-32; }
		if( from_c >= 224 && from_c < 247 ) { return from_c-32; }
		if( from_c >= 248 && from_c < 255 ) { return from_c-32; }
		if( from_c >= 945 && from_c < 962 ) { return from_c-32; }
		if( from_c >= 963 && from_c < 972 ) { return from_c-32; }
		if( from_c >= 1072 && from_c < 1104 ) { return from_c-32; }
		if( from_c >= 65345 && from_c < 65371 ) { return from_c-32; }
		if( from_c >= 71872 && from_c < 71904 ) { return from_c-32; }
		if( from_c >= 93792 && from_c < 93824 ) { return from_c-32; }
		if( from_c == 181 ) { return from_c+743; }
		if( from_c == 255 ) { return from_c+121; }
		if( from_c == 257 ) { return from_c-1; }
		if( from_c == 259 ) { return from_c-1; }
		if( from_c == 261 ) { return from_c-1; }
		if( from_c == 263 ) { return from_c-1; }
		if( from_c == 265 ) { return from_c-1; }
		if( from_c == 267 ) { return from_c-1; }
		if( from_c == 269 ) { return from_c-1; }
		if( from_c == 271 ) { return from_c-1; }
		if( from_c == 273 ) { return from_c-1; }
		if( from_c == 275 ) { return from_c-1; }
		if( from_c == 277 ) { return from_c-1; }
		if( from_c == 279 ) { return from_c-1; }
		if( from_c == 281 ) { return from_c-1; }
		if( from_c == 283 ) { return from_c-1; }
		if( from_c == 285 ) { return from_c-1; }
		if( from_c == 287 ) { return from_c-1; }
		if( from_c == 289 ) { return from_c-1; }
		if( from_c == 291 ) { return from_c-1; }
		if( from_c == 293 ) { return from_c-1; }
		if( from_c == 295 ) { return from_c-1; }
		if( from_c == 297 ) { return from_c-1; }
		if( from_c == 299 ) { return from_c-1; }
		if( from_c == 301 ) { return from_c-1; }
		if( from_c == 303 ) { return from_c-1; }
		if( from_c == 307 ) { return from_c-1; }
		if( from_c == 309 ) { return from_c-1; }
		if( from_c == 311 ) { return from_c-1; }
		if( from_c == 314 ) { return from_c-1; }
		if( from_c == 316 ) { return from_c-1; }
		if( from_c == 318 ) { return from_c-1; }
		if( from_c == 320 ) { return from_c-1; }
		if( from_c == 322 ) { return from_c-1; }
		if( from_c == 324 ) { return from_c-1; }
		if( from_c == 326 ) { return from_c-1; }
		if( from_c == 328 ) { return from_c-1; }
		if( from_c == 331 ) { return from_c-1; }
		if( from_c == 333 ) { return from_c-1; }
		if( from_c == 335 ) { return from_c-1; }
		if( from_c == 337 ) { return from_c-1; }
		if( from_c == 339 ) { return from_c-1; }
		if( from_c == 341 ) { return from_c-1; }
		if( from_c == 343 ) { return from_c-1; }
		if( from_c == 345 ) { return from_c-1; }
		if( from_c == 347 ) { return from_c-1; }
		if( from_c == 349 ) { return from_c-1; }
		if( from_c == 351 ) { return from_c-1; }
		if( from_c == 353 ) { return from_c-1; }
		if( from_c == 355 ) { return from_c-1; }
		if( from_c == 357 ) { return from_c-1; }
		if( from_c == 359 ) { return from_c-1; }
		if( from_c == 361 ) { return from_c-1; }
		if( from_c == 363 ) { return from_c-1; }
		if( from_c == 365 ) { return from_c-1; }
		if( from_c == 367 ) { return from_c-1; }
		if( from_c == 369 ) { return from_c-1; }
		if( from_c == 371 ) { return from_c-1; }
		if( from_c == 373 ) { return from_c-1; }
		if( from_c == 375 ) { return from_c-1; }
		if( from_c == 378 ) { return from_c-1; }
		if( from_c == 380 ) { return from_c-1; }
		if( from_c == 382 ) { return from_c-1; }
		if( from_c == 387 ) { return from_c-1; }
		if( from_c == 389 ) { return from_c-1; }
		if( from_c == 392 ) { return from_c-1; }
		if( from_c == 396 ) { return from_c-1; }
		if( from_c == 402 ) { return from_c-1; }
		if( from_c == 409 ) { return from_c-1; }
		if( from_c == 417 ) { return from_c-1; }
		if( from_c == 419 ) { return from_c-1; }
		if( from_c == 421 ) { return from_c-1; }
		if( from_c == 424 ) { return from_c-1; }
		if( from_c == 429 ) { return from_c-1; }
		if( from_c == 432 ) { return from_c-1; }
		if( from_c == 436 ) { return from_c-1; }
		if( from_c == 438 ) { return from_c-1; }
		if( from_c == 441 ) { return from_c-1; }
		if( from_c == 445 ) { return from_c-1; }
		if( from_c == 453 ) { return from_c-1; }
		if( from_c == 456 ) { return from_c-1; }
		if( from_c == 459 ) { return from_c-1; }
		if( from_c == 462 ) { return from_c-1; }
		if( from_c == 464 ) { return from_c-1; }
		if( from_c == 466 ) { return from_c-1; }
		if( from_c == 468 ) { return from_c-1; }
		if( from_c == 470 ) { return from_c-1; }
		if( from_c == 472 ) { return from_c-1; }
		if( from_c == 474 ) { return from_c-1; }
		if( from_c == 476 ) { return from_c-1; }
		if( from_c == 479 ) { return from_c-1; }
		if( from_c == 481 ) { return from_c-1; }
		if( from_c == 483 ) { return from_c-1; }
		if( from_c == 485 ) { return from_c-1; }
		if( from_c == 487 ) { return from_c-1; }
		if( from_c == 489 ) { return from_c-1; }
		if( from_c == 491 ) { return from_c-1; }
		if( from_c == 493 ) { return from_c-1; }
		if( from_c == 495 ) { return from_c-1; }
		if( from_c == 498 ) { return from_c-1; }
		if( from_c == 501 ) { return from_c-1; }
		if( from_c == 505 ) { return from_c-1; }
		if( from_c == 507 ) { return from_c-1; }
		if( from_c == 509 ) { return from_c-1; }
		if( from_c == 511 ) { return from_c-1; }
		if( from_c == 513 ) { return from_c-1; }
		if( from_c == 515 ) { return from_c-1; }
		if( from_c == 517 ) { return from_c-1; }
		if( from_c == 519 ) { return from_c-1; }
		if( from_c == 521 ) { return from_c-1; }
		if( from_c == 523 ) { return from_c-1; }
		if( from_c == 525 ) { return from_c-1; }
		if( from_c == 527 ) { return from_c-1; }
		if( from_c == 529 ) { return from_c-1; }
		if( from_c == 531 ) { return from_c-1; }
		if( from_c == 533 ) { return from_c-1; }
		if( from_c == 535 ) { return from_c-1; }
		if( from_c == 537 ) { return from_c-1; }
		if( from_c == 539 ) { return from_c-1; }
		if( from_c == 541 ) { return from_c-1; }
		if( from_c == 543 ) { return from_c-1; }
		if( from_c == 547 ) { return from_c-1; }
		if( from_c == 549 ) { return from_c-1; }
		if( from_c == 551 ) { return from_c-1; }
		if( from_c == 553 ) { return from_c-1; }
		if( from_c == 555 ) { return from_c-1; }
		if( from_c == 557 ) { return from_c-1; }
		if( from_c == 559 ) { return from_c-1; }
		if( from_c == 561 ) { return from_c-1; }
		if( from_c == 563 ) { return from_c-1; }
		if( from_c == 572 ) { return from_c-1; }
		if( from_c == 578 ) { return from_c-1; }
		if( from_c == 583 ) { return from_c-1; }
		if( from_c == 585 ) { return from_c-1; }
		if( from_c == 587 ) { return from_c-1; }
		if( from_c == 589 ) { return from_c-1; }
		if( from_c == 591 ) { return from_c-1; }
		if( from_c == 881 ) { return from_c-1; }
		if( from_c == 883 ) { return from_c-1; }
		if( from_c == 887 ) { return from_c-1; }
		if( from_c == 985 ) { return from_c-1; }
		if( from_c == 987 ) { return from_c-1; }
		if( from_c == 989 ) { return from_c-1; }
		if( from_c == 991 ) { return from_c-1; }
		if( from_c == 993 ) { return from_c-1; }
		if( from_c == 995 ) { return from_c-1; }
		if( from_c == 997 ) { return from_c-1; }
		if( from_c == 999 ) { return from_c-1; }
		if( from_c == 1001 ) { return from_c-1; }
		if( from_c == 1003 ) { return from_c-1; }
		if( from_c == 1005 ) { return from_c-1; }
		if( from_c == 1007 ) { return from_c-1; }
		if( from_c == 1016 ) { return from_c-1; }
		if( from_c == 1019 ) { return from_c-1; }
		if( from_c == 1121 ) { return from_c-1; }
		if( from_c == 1123 ) { return from_c-1; }
		if( from_c == 1125 ) { return from_c-1; }
		if( from_c == 1127 ) { return from_c-1; }
		if( from_c == 1129 ) { return from_c-1; }
		if( from_c == 1131 ) { return from_c-1; }
		if( from_c == 1133 ) { return from_c-1; }
		if( from_c == 1135 ) { return from_c-1; }
		if( from_c == 1137 ) { return from_c-1; }
		if( from_c == 1139 ) { return from_c-1; }
		if( from_c == 1141 ) { return from_c-1; }
		if( from_c == 1143 ) { return from_c-1; }
		if( from_c == 1145 ) { return from_c-1; }
		if( from_c == 1147 ) { return from_c-1; }
		if( from_c == 1149 ) { return from_c-1; }
		if( from_c == 1151 ) { return from_c-1; }
		if( from_c == 1153 ) { return from_c-1; }
		if( from_c == 1163 ) { return from_c-1; }
		if( from_c == 1165 ) { return from_c-1; }
		if( from_c == 1167 ) { return from_c-1; }
		if( from_c == 1169 ) { return from_c-1; }
		if( from_c == 1171 ) { return from_c-1; }
		if( from_c == 1173 ) { return from_c-1; }
		if( from_c == 1175 ) { return from_c-1; }
		if( from_c == 1177 ) { return from_c-1; }
		if( from_c == 1179 ) { return from_c-1; }
		if( from_c == 1181 ) { return from_c-1; }
		if( from_c == 1183 ) { return from_c-1; }
		if( from_c == 1185 ) { return from_c-1; }
		if( from_c == 1187 ) { return from_c-1; }
		if( from_c == 1189 ) { return from_c-1; }
		if( from_c == 1191 ) { return from_c-1; }
		if( from_c == 1193 ) { return from_c-1; }
		if( from_c == 1195 ) { return from_c-1; }
		if( from_c == 1197 ) { return from_c-1; }
		if( from_c == 1199 ) { return from_c-1; }
		if( from_c == 1201 ) { return from_c-1; }
		if( from_c == 1203 ) { return from_c-1; }
		if( from_c == 1205 ) { return from_c-1; }
		if( from_c == 1207 ) { return from_c-1; }
		if( from_c == 1209 ) { return from_c-1; }
		if( from_c == 1211 ) { return from_c-1; }
		if( from_c == 1213 ) { return from_c-1; }
		if( from_c == 1215 ) { return from_c-1; }
		if( from_c == 1218 ) { return from_c-1; }
		if( from_c == 1220 ) { return from_c-1; }
		if( from_c == 1222 ) { return from_c-1; }
		if( from_c == 1224 ) { return from_c-1; }
		if( from_c == 1226 ) { return from_c-1; }
		if( from_c == 1228 ) { return from_c-1; }
		if( from_c == 1230 ) { return from_c-1; }
		if( from_c == 1233 ) { return from_c-1; }
		if( from_c == 1235 ) { return from_c-1; }
		if( from_c == 1237 ) { return from_c-1; }
		if( from_c == 1239 ) { return from_c-1; }
		if( from_c == 1241 ) { return from_c-1; }
		if( from_c == 1243 ) { return from_c-1; }
		if( from_c == 1245 ) { return from_c-1; }
		if( from_c == 1247 ) { return from_c-1; }
		if( from_c == 1249 ) { return from_c-1; }
		if( from_c == 1251 ) { return from_c-1; }
		if( from_c == 1253 ) { return from_c-1; }
		if( from_c == 1255 ) { return from_c-1; }
		if( from_c == 1257 ) { return from_c-1; }
		if( from_c == 1259 ) { return from_c-1; }
		if( from_c == 1261 ) { return from_c-1; }
		if( from_c == 1263 ) { return from_c-1; }
		if( from_c == 1265 ) { return from_c-1; }
		if( from_c == 1267 ) { return from_c-1; }
		if( from_c == 1269 ) { return from_c-1; }
		if( from_c == 1271 ) { return from_c-1; }
		if( from_c == 1273 ) { return from_c-1; }
		if( from_c == 1275 ) { return from_c-1; }
		if( from_c == 1277 ) { return from_c-1; }
		if( from_c == 1279 ) { return from_c-1; }
		if( from_c == 1281 ) { return from_c-1; }
		if( from_c == 1283 ) { return from_c-1; }
		if( from_c == 1285 ) { return from_c-1; }
		if( from_c == 1287 ) { return from_c-1; }
		if( from_c == 1289 ) { return from_c-1; }
		if( from_c == 1291 ) { return from_c-1; }
		if( from_c == 1293 ) { return from_c-1; }
		if( from_c == 1295 ) { return from_c-1; }
		if( from_c == 1297 ) { return from_c-1; }
		if( from_c == 1299 ) { return from_c-1; }
		if( from_c == 1301 ) { return from_c-1; }
		if( from_c == 1303 ) { return from_c-1; }
		if( from_c == 1305 ) { return from_c-1; }
		if( from_c == 1307 ) { return from_c-1; }
		if( from_c == 1309 ) { return from_c-1; }
		if( from_c == 1311 ) { return from_c-1; }
		if( from_c == 1313 ) { return from_c-1; }
		if( from_c == 1315 ) { return from_c-1; }
		if( from_c == 1317 ) { return from_c-1; }
		if( from_c == 1319 ) { return from_c-1; }
		if( from_c == 1321 ) { return from_c-1; }
		if( from_c == 1323 ) { return from_c-1; }
		if( from_c == 1325 ) { return from_c-1; }
		if( from_c == 1327 ) { return from_c-1; }
		if( from_c == 7681 ) { return from_c-1; }
		if( from_c == 7683 ) { return from_c-1; }
		if( from_c == 7685 ) { return from_c-1; }
		if( from_c == 7687 ) { return from_c-1; }
		if( from_c == 7689 ) { return from_c-1; }
		if( from_c == 7691 ) { return from_c-1; }
		if( from_c == 7693 ) { return from_c-1; }
		if( from_c == 7695 ) { return from_c-1; }
		if( from_c == 7697 ) { return from_c-1; }
		if( from_c == 7699 ) { return from_c-1; }
		if( from_c == 7701 ) { return from_c-1; }
		if( from_c == 7703 ) { return from_c-1; }
		if( from_c == 7705 ) { return from_c-1; }
		if( from_c == 7707 ) { return from_c-1; }
		if( from_c == 7709 ) { return from_c-1; }
		if( from_c == 7711 ) { return from_c-1; }
		if( from_c == 7713 ) { return from_c-1; }
		if( from_c == 7715 ) { return from_c-1; }
		if( from_c == 7717 ) { return from_c-1; }
		if( from_c == 7719 ) { return from_c-1; }
		if( from_c == 7721 ) { return from_c-1; }
		if( from_c == 7723 ) { return from_c-1; }
		if( from_c == 7725 ) { return from_c-1; }
		if( from_c == 7727 ) { return from_c-1; }
		if( from_c == 7729 ) { return from_c-1; }
		if( from_c == 7731 ) { return from_c-1; }
		if( from_c == 7733 ) { return from_c-1; }
		if( from_c == 7735 ) { return from_c-1; }
		if( from_c == 7737 ) { return from_c-1; }
		if( from_c == 7739 ) { return from_c-1; }
		if( from_c == 7741 ) { return from_c-1; }
		if( from_c == 7743 ) { return from_c-1; }
		if( from_c == 7745 ) { return from_c-1; }
		if( from_c == 7747 ) { return from_c-1; }
		if( from_c == 7749 ) { return from_c-1; }
		if( from_c == 7751 ) { return from_c-1; }
		if( from_c == 7753 ) { return from_c-1; }
		if( from_c == 7755 ) { return from_c-1; }
		if( from_c == 7757 ) { return from_c-1; }
		if( from_c == 7759 ) { return from_c-1; }
		if( from_c == 7761 ) { return from_c-1; }
		if( from_c == 7763 ) { return from_c-1; }
		if( from_c == 7765 ) { return from_c-1; }
		if( from_c == 7767 ) { return from_c-1; }
		if( from_c == 7769 ) { return from_c-1; }
		if( from_c == 7771 ) { return from_c-1; }
		if( from_c == 7773 ) { return from_c-1; }
		if( from_c == 7775 ) { return from_c-1; }
		if( from_c == 7777 ) { return from_c-1; }
		if( from_c == 7779 ) { return from_c-1; }
		if( from_c == 7781 ) { return from_c-1; }
		if( from_c == 7783 ) { return from_c-1; }
		if( from_c == 7785 ) { return from_c-1; }
		if( from_c == 7787 ) { return from_c-1; }
		if( from_c == 7789 ) { return from_c-1; }
		if( from_c == 7791 ) { return from_c-1; }
		if( from_c == 7793 ) { return from_c-1; }
		if( from_c == 7795 ) { return from_c-1; }
		if( from_c == 7797 ) { return from_c-1; }
		if( from_c == 7799 ) { return from_c-1; }
		if( from_c == 7801 ) { return from_c-1; }
		if( from_c == 7803 ) { return from_c-1; }
		if( from_c == 7805 ) { return from_c-1; }
		if( from_c == 7807 ) { return from_c-1; }
		if( from_c == 7809 ) { return from_c-1; }
		if( from_c == 7811 ) { return from_c-1; }
		if( from_c == 7813 ) { return from_c-1; }
		if( from_c == 7815 ) { return from_c-1; }
		if( from_c == 7817 ) { return from_c-1; }
		if( from_c == 7819 ) { return from_c-1; }
		if( from_c == 7821 ) { return from_c-1; }
		if( from_c == 7823 ) { return from_c-1; }
		if( from_c == 7825 ) { return from_c-1; }
		if( from_c == 7827 ) { return from_c-1; }
		if( from_c == 7829 ) { return from_c-1; }
		if( from_c == 7841 ) { return from_c-1; }
		if( from_c == 7843 ) { return from_c-1; }
		if( from_c == 7845 ) { return from_c-1; }
		if( from_c == 7847 ) { return from_c-1; }
		if( from_c == 7849 ) { return from_c-1; }
		if( from_c == 7851 ) { return from_c-1; }
		if( from_c == 7853 ) { return from_c-1; }
		if( from_c == 7855 ) { return from_c-1; }
		if( from_c == 7857 ) { return from_c-1; }
		if( from_c == 7859 ) { return from_c-1; }
		if( from_c == 7861 ) { return from_c-1; }
		if( from_c == 7863 ) { return from_c-1; }
		if( from_c == 7865 ) { return from_c-1; }
		if( from_c == 7867 ) { return from_c-1; }
		if( from_c == 7869 ) { return from_c-1; }
		if( from_c == 7871 ) { return from_c-1; }
		if( from_c == 7873 ) { return from_c-1; }
		if( from_c == 7875 ) { return from_c-1; }
		if( from_c == 7877 ) { return from_c-1; }
		if( from_c == 7879 ) { return from_c-1; }
		if( from_c == 7881 ) { return from_c-1; }
		if( from_c == 7883 ) { return from_c-1; }
		if( from_c == 7885 ) { return from_c-1; }
		if( from_c == 7887 ) { return from_c-1; }
		if( from_c == 7889 ) { return from_c-1; }
		if( from_c == 7891 ) { return from_c-1; }
		if( from_c == 7893 ) { return from_c-1; }
		if( from_c == 7895 ) { return from_c-1; }
		if( from_c == 7897 ) { return from_c-1; }
		if( from_c == 7899 ) { return from_c-1; }
		if( from_c == 7901 ) { return from_c-1; }
		if( from_c == 7903 ) { return from_c-1; }
		if( from_c == 7905 ) { return from_c-1; }
		if( from_c == 7907 ) { return from_c-1; }
		if( from_c == 7909 ) { return from_c-1; }
		if( from_c == 7911 ) { return from_c-1; }
		if( from_c == 7913 ) { return from_c-1; }
		if( from_c == 7915 ) { return from_c-1; }
		if( from_c == 7917 ) { return from_c-1; }
		if( from_c == 7919 ) { return from_c-1; }
		if( from_c == 7921 ) { return from_c-1; }
		if( from_c == 7923 ) { return from_c-1; }
		if( from_c == 7925 ) { return from_c-1; }
		if( from_c == 7927 ) { return from_c-1; }
		if( from_c == 7929 ) { return from_c-1; }
		if( from_c == 7931 ) { return from_c-1; }
		if( from_c == 7933 ) { return from_c-1; }
		if( from_c == 7935 ) { return from_c-1; }
		if( from_c == 8580 ) { return from_c-1; }
		if( from_c == 11361 ) { return from_c-1; }
		if( from_c == 11368 ) { return from_c-1; }
		if( from_c == 11370 ) { return from_c-1; }
		if( from_c == 11372 ) { return from_c-1; }
		if( from_c == 11379 ) { return from_c-1; }
		if( from_c == 11382 ) { return from_c-1; }
		if( from_c == 11393 ) { return from_c-1; }
		if( from_c == 11395 ) { return from_c-1; }
		if( from_c == 11397 ) { return from_c-1; }
		if( from_c == 11399 ) { return from_c-1; }
		if( from_c == 11401 ) { return from_c-1; }
		if( from_c == 11403 ) { return from_c-1; }
		if( from_c == 11405 ) { return from_c-1; }
		if( from_c == 11407 ) { return from_c-1; }
		if( from_c == 11409 ) { return from_c-1; }
		if( from_c == 11411 ) { return from_c-1; }
		if( from_c == 11413 ) { return from_c-1; }
		if( from_c == 11415 ) { return from_c-1; }
		if( from_c == 11417 ) { return from_c-1; }
		if( from_c == 11419 ) { return from_c-1; }
		if( from_c == 11421 ) { return from_c-1; }
		if( from_c == 11423 ) { return from_c-1; }
		if( from_c == 11425 ) { return from_c-1; }
		if( from_c == 11427 ) { return from_c-1; }
		if( from_c == 11429 ) { return from_c-1; }
		if( from_c == 11431 ) { return from_c-1; }
		if( from_c == 11433 ) { return from_c-1; }
		if( from_c == 11435 ) { return from_c-1; }
		if( from_c == 11437 ) { return from_c-1; }
		if( from_c == 11439 ) { return from_c-1; }
		if( from_c == 11441 ) { return from_c-1; }
		if( from_c == 11443 ) { return from_c-1; }
		if( from_c == 11445 ) { return from_c-1; }
		if( from_c == 11447 ) { return from_c-1; }
		if( from_c == 11449 ) { return from_c-1; }
		if( from_c == 11451 ) { return from_c-1; }
		if( from_c == 11453 ) { return from_c-1; }
		if( from_c == 11455 ) { return from_c-1; }
		if( from_c == 11457 ) { return from_c-1; }
		if( from_c == 11459 ) { return from_c-1; }
		if( from_c == 11461 ) { return from_c-1; }
		if( from_c == 11463 ) { return from_c-1; }
		if( from_c == 11465 ) { return from_c-1; }
		if( from_c == 11467 ) { return from_c-1; }
		if( from_c == 11469 ) { return from_c-1; }
		if( from_c == 11471 ) { return from_c-1; }
		if( from_c == 11473 ) { return from_c-1; }
		if( from_c == 11475 ) { return from_c-1; }
		if( from_c == 11477 ) { return from_c-1; }
		if( from_c == 11479 ) { return from_c-1; }
		if( from_c == 11481 ) { return from_c-1; }
		if( from_c == 11483 ) { return from_c-1; }
		if( from_c == 11485 ) { return from_c-1; }
		if( from_c == 11487 ) { return from_c-1; }
		if( from_c == 11489 ) { return from_c-1; }
		if( from_c == 11491 ) { return from_c-1; }
		if( from_c == 11500 ) { return from_c-1; }
		if( from_c == 11502 ) { return from_c-1; }
		if( from_c == 11507 ) { return from_c-1; }
		if( from_c == 42561 ) { return from_c-1; }
		if( from_c == 42563 ) { return from_c-1; }
		if( from_c == 42565 ) { return from_c-1; }
		if( from_c == 42567 ) { return from_c-1; }
		if( from_c == 42569 ) { return from_c-1; }
		if( from_c == 42571 ) { return from_c-1; }
		if( from_c == 42573 ) { return from_c-1; }
		if( from_c == 42575 ) { return from_c-1; }
		if( from_c == 42577 ) { return from_c-1; }
		if( from_c == 42579 ) { return from_c-1; }
		if( from_c == 42581 ) { return from_c-1; }
		if( from_c == 42583 ) { return from_c-1; }
		if( from_c == 42585 ) { return from_c-1; }
		if( from_c == 42587 ) { return from_c-1; }
		if( from_c == 42589 ) { return from_c-1; }
		if( from_c == 42591 ) { return from_c-1; }
		if( from_c == 42593 ) { return from_c-1; }
		if( from_c == 42595 ) { return from_c-1; }
		if( from_c == 42597 ) { return from_c-1; }
		if( from_c == 42599 ) { return from_c-1; }
		if( from_c == 42601 ) { return from_c-1; }
		if( from_c == 42603 ) { return from_c-1; }
		if( from_c == 42605 ) { return from_c-1; }
		if( from_c == 42625 ) { return from_c-1; }
		if( from_c == 42627 ) { return from_c-1; }
		if( from_c == 42629 ) { return from_c-1; }
		if( from_c == 42631 ) { return from_c-1; }
		if( from_c == 42633 ) { return from_c-1; }
		if( from_c == 42635 ) { return from_c-1; }
		if( from_c == 42637 ) { return from_c-1; }
		if( from_c == 42639 ) { return from_c-1; }
		if( from_c == 42641 ) { return from_c-1; }
		if( from_c == 42643 ) { return from_c-1; }
		if( from_c == 42645 ) { return from_c-1; }
		if( from_c == 42647 ) { return from_c-1; }
		if( from_c == 42649 ) { return from_c-1; }
		if( from_c == 42651 ) { return from_c-1; }
		if( from_c == 42787 ) { return from_c-1; }
		if( from_c == 42789 ) { return from_c-1; }
		if( from_c == 42791 ) { return from_c-1; }
		if( from_c == 42793 ) { return from_c-1; }
		if( from_c == 42795 ) { return from_c-1; }
		if( from_c == 42797 ) { return from_c-1; }
		if( from_c == 42799 ) { return from_c-1; }
		if( from_c == 42803 ) { return from_c-1; }
		if( from_c == 42805 ) { return from_c-1; }
		if( from_c == 42807 ) { return from_c-1; }
		if( from_c == 42809 ) { return from_c-1; }
		if( from_c == 42811 ) { return from_c-1; }
		if( from_c == 42813 ) { return from_c-1; }
		if( from_c == 42815 ) { return from_c-1; }
		if( from_c == 42817 ) { return from_c-1; }
		if( from_c == 42819 ) { return from_c-1; }
		if( from_c == 42821 ) { return from_c-1; }
		if( from_c == 42823 ) { return from_c-1; }
		if( from_c == 42825 ) { return from_c-1; }
		if( from_c == 42827 ) { return from_c-1; }
		if( from_c == 42829 ) { return from_c-1; }
		if( from_c == 42831 ) { return from_c-1; }
		if( from_c == 42833 ) { return from_c-1; }
		if( from_c == 42835 ) { return from_c-1; }
		if( from_c == 42837 ) { return from_c-1; }
		if( from_c == 42839 ) { return from_c-1; }
		if( from_c == 42841 ) { return from_c-1; }
		if( from_c == 42843 ) { return from_c-1; }
		if( from_c == 42845 ) { return from_c-1; }
		if( from_c == 42847 ) { return from_c-1; }
		if( from_c == 42849 ) { return from_c-1; }
		if( from_c == 42851 ) { return from_c-1; }
		if( from_c == 42853 ) { return from_c-1; }
		if( from_c == 42855 ) { return from_c-1; }
		if( from_c == 42857 ) { return from_c-1; }
		if( from_c == 42859 ) { return from_c-1; }
		if( from_c == 42861 ) { return from_c-1; }
		if( from_c == 42863 ) { return from_c-1; }
		if( from_c == 42874 ) { return from_c-1; }
		if( from_c == 42876 ) { return from_c-1; }
		if( from_c == 42879 ) { return from_c-1; }
		if( from_c == 42881 ) { return from_c-1; }
		if( from_c == 42883 ) { return from_c-1; }
		if( from_c == 42885 ) { return from_c-1; }
		if( from_c == 42887 ) { return from_c-1; }
		if( from_c == 42892 ) { return from_c-1; }
		if( from_c == 42897 ) { return from_c-1; }
		if( from_c == 42899 ) { return from_c-1; }
		if( from_c == 42903 ) { return from_c-1; }
		if( from_c == 42905 ) { return from_c-1; }
		if( from_c == 42907 ) { return from_c-1; }
		if( from_c == 42909 ) { return from_c-1; }
		if( from_c == 42911 ) { return from_c-1; }
		if( from_c == 42913 ) { return from_c-1; }
		if( from_c == 42915 ) { return from_c-1; }
		if( from_c == 42917 ) { return from_c-1; }
		if( from_c == 42919 ) { return from_c-1; }
		if( from_c == 42921 ) { return from_c-1; }
		if( from_c == 42933 ) { return from_c-1; }
		if( from_c == 42935 ) { return from_c-1; }
		if( from_c == 42937 ) { return from_c-1; }
		if( from_c == 42939 ) { return from_c-1; }
		if( from_c == 42941 ) { return from_c-1; }
		if( from_c == 42943 ) { return from_c-1; }
		if( from_c == 42945 ) { return from_c-1; }
		if( from_c == 42947 ) { return from_c-1; }
		if( from_c == 42952 ) { return from_c-1; }
		if( from_c == 42954 ) { return from_c-1; }
		if( from_c == 42961 ) { return from_c-1; }
		if( from_c == 42967 ) { return from_c-1; }
		if( from_c == 42969 ) { return from_c-1; }
		if( from_c == 42998 ) { return from_c-1; }
		if( from_c == 305 ) { return from_c-232; }
		if( from_c == 383 ) { return from_c-300; }
		if( from_c == 384 ) { return from_c+195; }
		if( from_c == 405 ) { return from_c+97; }
		if( from_c == 410 ) { return from_c+163; }
		if( from_c == 414 ) { return from_c+130; }
		if( from_c >= 891 && from_c < 894 ) { return from_c+130; }
		if( from_c == 447 ) { return from_c+56; }
		if( from_c == 454 ) { return from_c-2; }
		if( from_c == 457 ) { return from_c-2; }
		if( from_c == 460 ) { return from_c-2; }
		if( from_c == 499 ) { return from_c-2; }
		if( from_c == 477 ) { return from_c-79; }
		if( from_c >= 575 && from_c < 577 ) { return from_c+10815; }
		if( from_c == 592 ) { return from_c+10783; }
		if( from_c == 593 ) { return from_c+10780; }
		if( from_c == 594 ) { return from_c+10782; }
		if( from_c == 595 ) { return from_c-210; }
		if( from_c == 596 ) { return from_c-206; }
		if( from_c >= 598 && from_c < 600 ) { return from_c-205; }
		if( from_c == 608 ) { return from_c-205; }
		if( from_c == 601 ) { return from_c-202; }
		if( from_c == 603 ) { return from_c-203; }
		if( from_c == 604 ) { return from_c+42319; }
		if( from_c == 609 ) { return from_c+42315; }
		if( from_c == 611 ) { return from_c-207; }
		if( from_c == 613 ) { return from_c+42280; }
		if( from_c == 614 ) { return from_c+42308; }
		if( from_c == 618 ) { return from_c+42308; }
		if( from_c == 616 ) { return from_c-209; }
		if( from_c == 617 ) { return from_c-211; }
		if( from_c == 623 ) { return from_c-211; }
		if( from_c == 619 ) { return from_c+10743; }
		if( from_c == 620 ) { return from_c+42305; }
		if( from_c == 625 ) { return from_c+10749; }
		if( from_c == 626 ) { return from_c-213; }
		if( from_c == 629 ) { return from_c-214; }
		if( from_c == 637 ) { return from_c+10727; }
		if( from_c == 640 ) { return from_c-218; }
		if( from_c == 643 ) { return from_c-218; }
		if( from_c == 648 ) { return from_c-218; }
		if( from_c == 642 ) { return from_c+42307; }
		if( from_c == 647 ) { return from_c+42282; }
		if( from_c == 649 ) { return from_c-69; }
		if( from_c >= 650 && from_c < 652 ) { return from_c-217; }
		if( from_c == 652 ) { return from_c-71; }
		if( from_c == 658 ) { return from_c-219; }
		if( from_c == 669 ) { return from_c+42261; }
		if( from_c == 670 ) { return from_c+42258; }
		if( from_c == 837 ) { return from_c+84; }
		if( from_c == 940 ) { return from_c-38; }
		if( from_c >= 941 && from_c < 944 ) { return from_c-37; }
		if( from_c == 962 ) { return from_c-31; }
		if( from_c == 972 ) { return from_c-64; }
		if( from_c >= 68800 && from_c < 68851 ) { return from_c-64; }
		if( from_c >= 973 && from_c < 975 ) { return from_c-63; }
		if( from_c == 976 ) { return from_c-62; }
		if( from_c == 977 ) { return from_c-57; }
		if( from_c == 981 ) { return from_c-47; }
		if( from_c == 982 ) { return from_c-54; }
		if( from_c == 983 ) { return from_c-8; }
		if( from_c >= 5112 && from_c < 5118 ) { return from_c-8; }
		if( from_c == 1008 ) { return from_c-86; }
		if( from_c == 1009 ) { return from_c-80; }
		if( from_c >= 1104 && from_c < 1120 ) { return from_c-80; }
		if( from_c == 1010 ) { return from_c+7; }
		if( from_c == 8165 ) { return from_c+7; }
		if( from_c == 1011 ) { return from_c-116; }
		if( from_c == 1013 ) { return from_c-96; }
		if( from_c == 1231 ) { return from_c-15; }
		if( from_c >= 1377 && from_c < 1415 ) { return from_c-48; }
		if( from_c >= 11312 && from_c < 11360 ) { return from_c-48; }
		if( from_c >= 4304 && from_c < 4347 ) { return from_c+3008; }
		if( from_c >= 4349 && from_c < 4352 ) { return from_c+3008; }
		if( from_c == 7296 ) { return from_c-6254; }
		if( from_c == 7297 ) { return from_c-6253; }
		if( from_c == 7298 ) { return from_c-6244; }
		if( from_c >= 7299 && from_c < 7301 ) { return from_c-6242; }
		if( from_c == 7301 ) { return from_c-6243; }
		if( from_c == 7302 ) { return from_c-6236; }
		if( from_c == 7303 ) { return from_c-6181; }
		if( from_c == 7304 ) { return from_c+35266; }
		if( from_c == 7545 ) { return from_c+35332; }
		if( from_c == 7549 ) { return from_c+3814; }
		if( from_c == 7566 ) { return from_c+35384; }
		if( from_c == 7835 ) { return from_c-59; }
		if( from_c >= 7936 && from_c < 7944 ) { return from_c+8; }
		if( from_c >= 7952 && from_c < 7958 ) { return from_c+8; }
		if( from_c >= 7968 && from_c < 7976 ) { return from_c+8; }
		if( from_c >= 7984 && from_c < 7992 ) { return from_c+8; }
		if( from_c >= 8000 && from_c < 8006 ) { return from_c+8; }
		if( from_c == 8017 ) { return from_c+8; }
		if( from_c == 8019 ) { return from_c+8; }
		if( from_c == 8021 ) { return from_c+8; }
		if( from_c == 8023 ) { return from_c+8; }
		if( from_c >= 8032 && from_c < 8040 ) { return from_c+8; }
		if( from_c >= 8112 && from_c < 8114 ) { return from_c+8; }
		if( from_c >= 8144 && from_c < 8146 ) { return from_c+8; }
		if( from_c >= 8160 && from_c < 8162 ) { return from_c+8; }
		if( from_c >= 8048 && from_c < 8050 ) { return from_c+74; }
		if( from_c >= 8050 && from_c < 8054 ) { return from_c+86; }
		if( from_c >= 8054 && from_c < 8056 ) { return from_c+100; }
		if( from_c >= 8056 && from_c < 8058 ) { return from_c+128; }
		if( from_c >= 8058 && from_c < 8060 ) { return from_c+112; }
		if( from_c >= 8060 && from_c < 8062 ) { return from_c+126; }
		if( from_c == 8126 ) { return from_c-7205; }
		if( from_c == 8526 ) { return from_c-28; }
		if( from_c >= 8560 && from_c < 8576 ) { return from_c-16; }
		if( from_c >= 9424 && from_c < 9450 ) { return from_c-26; }
		if( from_c == 11365 ) { return from_c-10795; }
		if( from_c == 11366 ) { return from_c-10792; }
		if( from_c >= 11520 && from_c < 11558 ) { return from_c-7264; }
		if( from_c == 11559 ) { return from_c-7264; }
		if( from_c == 11565 ) { return from_c-7264; }
		if( from_c == 42900 ) { return from_c+48; }
		if( from_c == 43859 ) { return from_c-928; }
		if( from_c >= 43888 && from_c < 43968 ) { return from_c-38864; }
		if( from_c >= 66600 && from_c < 66640 ) { return from_c-40; }
		if( from_c >= 66776 && from_c < 66812 ) { return from_c-40; }
		if( from_c >= 66967 && from_c < 66978 ) { return from_c-39; }
		if( from_c >= 66979 && from_c < 66994 ) { return from_c-39; }
		if( from_c >= 66995 && from_c < 67002 ) { return from_c-39; }
		if( from_c >= 67003 && from_c < 67005 ) { return from_c-39; }
		if( from_c >= 125218 && from_c < 125252 ) { return from_c-34; }

		return from_c;
	}
	
	char32_t to_lower(char32_t from_c) noexcept {
		if( from_c >= 65 && from_c < 91 ) { return from_c+32; }
		if( from_c >= 192 && from_c < 215 ) { return from_c+32; }
		if( from_c >= 216 && from_c < 223 ) { return from_c+32; }
		if( from_c >= 913 && from_c < 930 ) { return from_c+32; }
		if( from_c >= 931 && from_c < 940 ) { return from_c+32; }
		if( from_c >= 1040 && from_c < 1072 ) { return from_c+32; }
		if( from_c >= 65313 && from_c < 65339 ) { return from_c+32; }
		if( from_c >= 71840 && from_c < 71872 ) { return from_c+32; }
		if( from_c >= 93760 && from_c < 93792 ) { return from_c+32; }
		if( from_c == 256 ) { return from_c+1; }
		if( from_c == 258 ) { return from_c+1; }
		if( from_c == 260 ) { return from_c+1; }
		if( from_c == 262 ) { return from_c+1; }
		if( from_c == 264 ) { return from_c+1; }
		if( from_c == 266 ) { return from_c+1; }
		if( from_c == 268 ) { return from_c+1; }
		if( from_c == 270 ) { return from_c+1; }
		if( from_c == 272 ) { return from_c+1; }
		if( from_c == 274 ) { return from_c+1; }
		if( from_c == 276 ) { return from_c+1; }
		if( from_c == 278 ) { return from_c+1; }
		if( from_c == 280 ) { return from_c+1; }
		if( from_c == 282 ) { return from_c+1; }
		if( from_c == 284 ) { return from_c+1; }
		if( from_c == 286 ) { return from_c+1; }
		if( from_c == 288 ) { return from_c+1; }
		if( from_c == 290 ) { return from_c+1; }
		if( from_c == 292 ) { return from_c+1; }
		if( from_c == 294 ) { return from_c+1; }
		if( from_c == 296 ) { return from_c+1; }
		if( from_c == 298 ) { return from_c+1; }
		if( from_c == 300 ) { return from_c+1; }
		if( from_c == 302 ) { return from_c+1; }
		if( from_c == 306 ) { return from_c+1; }
		if( from_c == 308 ) { return from_c+1; }
		if( from_c == 310 ) { return from_c+1; }
		if( from_c == 313 ) { return from_c+1; }
		if( from_c == 315 ) { return from_c+1; }
		if( from_c == 317 ) { return from_c+1; }
		if( from_c == 319 ) { return from_c+1; }
		if( from_c == 321 ) { return from_c+1; }
		if( from_c == 323 ) { return from_c+1; }
		if( from_c == 325 ) { return from_c+1; }
		if( from_c == 327 ) { return from_c+1; }
		if( from_c == 330 ) { return from_c+1; }
		if( from_c == 332 ) { return from_c+1; }
		if( from_c == 334 ) { return from_c+1; }
		if( from_c == 336 ) { return from_c+1; }
		if( from_c == 338 ) { return from_c+1; }
		if( from_c == 340 ) { return from_c+1; }
		if( from_c == 342 ) { return from_c+1; }
		if( from_c == 344 ) { return from_c+1; }
		if( from_c == 346 ) { return from_c+1; }
		if( from_c == 348 ) { return from_c+1; }
		if( from_c == 350 ) { return from_c+1; }
		if( from_c == 352 ) { return from_c+1; }
		if( from_c == 354 ) { return from_c+1; }
		if( from_c == 356 ) { return from_c+1; }
		if( from_c == 358 ) { return from_c+1; }
		if( from_c == 360 ) { return from_c+1; }
		if( from_c == 362 ) { return from_c+1; }
		if( from_c == 364 ) { return from_c+1; }
		if( from_c == 366 ) { return from_c+1; }
		if( from_c == 368 ) { return from_c+1; }
		if( from_c == 370 ) { return from_c+1; }
		if( from_c == 372 ) { return from_c+1; }
		if( from_c == 374 ) { return from_c+1; }
		if( from_c == 377 ) { return from_c+1; }
		if( from_c == 379 ) { return from_c+1; }
		if( from_c == 381 ) { return from_c+1; }
		if( from_c == 386 ) { return from_c+1; }
		if( from_c == 388 ) { return from_c+1; }
		if( from_c == 391 ) { return from_c+1; }
		if( from_c == 395 ) { return from_c+1; }
		if( from_c == 401 ) { return from_c+1; }
		if( from_c == 408 ) { return from_c+1; }
		if( from_c == 416 ) { return from_c+1; }
		if( from_c == 418 ) { return from_c+1; }
		if( from_c == 420 ) { return from_c+1; }
		if( from_c == 423 ) { return from_c+1; }
		if( from_c == 428 ) { return from_c+1; }
		if( from_c == 431 ) { return from_c+1; }
		if( from_c == 435 ) { return from_c+1; }
		if( from_c == 437 ) { return from_c+1; }
		if( from_c == 440 ) { return from_c+1; }
		if( from_c == 444 ) { return from_c+1; }
		if( from_c == 453 ) { return from_c+1; }
		if( from_c == 456 ) { return from_c+1; }
		if( from_c == 459 ) { return from_c+1; }
		if( from_c == 461 ) { return from_c+1; }
		if( from_c == 463 ) { return from_c+1; }
		if( from_c == 465 ) { return from_c+1; }
		if( from_c == 467 ) { return from_c+1; }
		if( from_c == 469 ) { return from_c+1; }
		if( from_c == 471 ) { return from_c+1; }
		if( from_c == 473 ) { return from_c+1; }
		if( from_c == 475 ) { return from_c+1; }
		if( from_c == 478 ) { return from_c+1; }
		if( from_c == 480 ) { return from_c+1; }
		if( from_c == 482 ) { return from_c+1; }
		if( from_c == 484 ) { return from_c+1; }
		if( from_c == 486 ) { return from_c+1; }
		if( from_c == 488 ) { return from_c+1; }
		if( from_c == 490 ) { return from_c+1; }
		if( from_c == 492 ) { return from_c+1; }
		if( from_c == 494 ) { return from_c+1; }
		if( from_c == 498 ) { return from_c+1; }
		if( from_c == 500 ) { return from_c+1; }
		if( from_c == 504 ) { return from_c+1; }
		if( from_c == 506 ) { return from_c+1; }
		if( from_c == 508 ) { return from_c+1; }
		if( from_c == 510 ) { return from_c+1; }
		if( from_c == 512 ) { return from_c+1; }
		if( from_c == 514 ) { return from_c+1; }
		if( from_c == 516 ) { return from_c+1; }
		if( from_c == 518 ) { return from_c+1; }
		if( from_c == 520 ) { return from_c+1; }
		if( from_c == 522 ) { return from_c+1; }
		if( from_c == 524 ) { return from_c+1; }
		if( from_c == 526 ) { return from_c+1; }
		if( from_c == 528 ) { return from_c+1; }
		if( from_c == 530 ) { return from_c+1; }
		if( from_c == 532 ) { return from_c+1; }
		if( from_c == 534 ) { return from_c+1; }
		if( from_c == 536 ) { return from_c+1; }
		if( from_c == 538 ) { return from_c+1; }
		if( from_c == 540 ) { return from_c+1; }
		if( from_c == 542 ) { return from_c+1; }
		if( from_c == 546 ) { return from_c+1; }
		if( from_c == 548 ) { return from_c+1; }
		if( from_c == 550 ) { return from_c+1; }
		if( from_c == 552 ) { return from_c+1; }
		if( from_c == 554 ) { return from_c+1; }
		if( from_c == 556 ) { return from_c+1; }
		if( from_c == 558 ) { return from_c+1; }
		if( from_c == 560 ) { return from_c+1; }
		if( from_c == 562 ) { return from_c+1; }
		if( from_c == 571 ) { return from_c+1; }
		if( from_c == 577 ) { return from_c+1; }
		if( from_c == 582 ) { return from_c+1; }
		if( from_c == 584 ) { return from_c+1; }
		if( from_c == 586 ) { return from_c+1; }
		if( from_c == 588 ) { return from_c+1; }
		if( from_c == 590 ) { return from_c+1; }
		if( from_c == 880 ) { return from_c+1; }
		if( from_c == 882 ) { return from_c+1; }
		if( from_c == 886 ) { return from_c+1; }
		if( from_c == 984 ) { return from_c+1; }
		if( from_c == 986 ) { return from_c+1; }
		if( from_c == 988 ) { return from_c+1; }
		if( from_c == 990 ) { return from_c+1; }
		if( from_c == 992 ) { return from_c+1; }
		if( from_c == 994 ) { return from_c+1; }
		if( from_c == 996 ) { return from_c+1; }
		if( from_c == 998 ) { return from_c+1; }
		if( from_c == 1000 ) { return from_c+1; }
		if( from_c == 1002 ) { return from_c+1; }
		if( from_c == 1004 ) { return from_c+1; }
		if( from_c == 1006 ) { return from_c+1; }
		if( from_c == 1015 ) { return from_c+1; }
		if( from_c == 1018 ) { return from_c+1; }
		if( from_c == 1120 ) { return from_c+1; }
		if( from_c == 1122 ) { return from_c+1; }
		if( from_c == 1124 ) { return from_c+1; }
		if( from_c == 1126 ) { return from_c+1; }
		if( from_c == 1128 ) { return from_c+1; }
		if( from_c == 1130 ) { return from_c+1; }
		if( from_c == 1132 ) { return from_c+1; }
		if( from_c == 1134 ) { return from_c+1; }
		if( from_c == 1136 ) { return from_c+1; }
		if( from_c == 1138 ) { return from_c+1; }
		if( from_c == 1140 ) { return from_c+1; }
		if( from_c == 1142 ) { return from_c+1; }
		if( from_c == 1144 ) { return from_c+1; }
		if( from_c == 1146 ) { return from_c+1; }
		if( from_c == 1148 ) { return from_c+1; }
		if( from_c == 1150 ) { return from_c+1; }
		if( from_c == 1152 ) { return from_c+1; }
		if( from_c == 1162 ) { return from_c+1; }
		if( from_c == 1164 ) { return from_c+1; }
		if( from_c == 1166 ) { return from_c+1; }
		if( from_c == 1168 ) { return from_c+1; }
		if( from_c == 1170 ) { return from_c+1; }
		if( from_c == 1172 ) { return from_c+1; }
		if( from_c == 1174 ) { return from_c+1; }
		if( from_c == 1176 ) { return from_c+1; }
		if( from_c == 1178 ) { return from_c+1; }
		if( from_c == 1180 ) { return from_c+1; }
		if( from_c == 1182 ) { return from_c+1; }
		if( from_c == 1184 ) { return from_c+1; }
		if( from_c == 1186 ) { return from_c+1; }
		if( from_c == 1188 ) { return from_c+1; }
		if( from_c == 1190 ) { return from_c+1; }
		if( from_c == 1192 ) { return from_c+1; }
		if( from_c == 1194 ) { return from_c+1; }
		if( from_c == 1196 ) { return from_c+1; }
		if( from_c == 1198 ) { return from_c+1; }
		if( from_c == 1200 ) { return from_c+1; }
		if( from_c == 1202 ) { return from_c+1; }
		if( from_c == 1204 ) { return from_c+1; }
		if( from_c == 1206 ) { return from_c+1; }
		if( from_c == 1208 ) { return from_c+1; }
		if( from_c == 1210 ) { return from_c+1; }
		if( from_c == 1212 ) { return from_c+1; }
		if( from_c == 1214 ) { return from_c+1; }
		if( from_c == 1217 ) { return from_c+1; }
		if( from_c == 1219 ) { return from_c+1; }
		if( from_c == 1221 ) { return from_c+1; }
		if( from_c == 1223 ) { return from_c+1; }
		if( from_c == 1225 ) { return from_c+1; }
		if( from_c == 1227 ) { return from_c+1; }
		if( from_c == 1229 ) { return from_c+1; }
		if( from_c == 1232 ) { return from_c+1; }
		if( from_c == 1234 ) { return from_c+1; }
		if( from_c == 1236 ) { return from_c+1; }
		if( from_c == 1238 ) { return from_c+1; }
		if( from_c == 1240 ) { return from_c+1; }
		if( from_c == 1242 ) { return from_c+1; }
		if( from_c == 1244 ) { return from_c+1; }
		if( from_c == 1246 ) { return from_c+1; }
		if( from_c == 1248 ) { return from_c+1; }
		if( from_c == 1250 ) { return from_c+1; }
		if( from_c == 1252 ) { return from_c+1; }
		if( from_c == 1254 ) { return from_c+1; }
		if( from_c == 1256 ) { return from_c+1; }
		if( from_c == 1258 ) { return from_c+1; }
		if( from_c == 1260 ) { return from_c+1; }
		if( from_c == 1262 ) { return from_c+1; }
		if( from_c == 1264 ) { return from_c+1; }
		if( from_c == 1266 ) { return from_c+1; }
		if( from_c == 1268 ) { return from_c+1; }
		if( from_c == 1270 ) { return from_c+1; }
		if( from_c == 1272 ) { return from_c+1; }
		if( from_c == 1274 ) { return from_c+1; }
		if( from_c == 1276 ) { return from_c+1; }
		if( from_c == 1278 ) { return from_c+1; }
		if( from_c == 1280 ) { return from_c+1; }
		if( from_c == 1282 ) { return from_c+1; }
		if( from_c == 1284 ) { return from_c+1; }
		if( from_c == 1286 ) { return from_c+1; }
		if( from_c == 1288 ) { return from_c+1; }
		if( from_c == 1290 ) { return from_c+1; }
		if( from_c == 1292 ) { return from_c+1; }
		if( from_c == 1294 ) { return from_c+1; }
		if( from_c == 1296 ) { return from_c+1; }
		if( from_c == 1298 ) { return from_c+1; }
		if( from_c == 1300 ) { return from_c+1; }
		if( from_c == 1302 ) { return from_c+1; }
		if( from_c == 1304 ) { return from_c+1; }
		if( from_c == 1306 ) { return from_c+1; }
		if( from_c == 1308 ) { return from_c+1; }
		if( from_c == 1310 ) { return from_c+1; }
		if( from_c == 1312 ) { return from_c+1; }
		if( from_c == 1314 ) { return from_c+1; }
		if( from_c == 1316 ) { return from_c+1; }
		if( from_c == 1318 ) { return from_c+1; }
		if( from_c == 1320 ) { return from_c+1; }
		if( from_c == 1322 ) { return from_c+1; }
		if( from_c == 1324 ) { return from_c+1; }
		if( from_c == 1326 ) { return from_c+1; }
		if( from_c == 7680 ) { return from_c+1; }
		if( from_c == 7682 ) { return from_c+1; }
		if( from_c == 7684 ) { return from_c+1; }
		if( from_c == 7686 ) { return from_c+1; }
		if( from_c == 7688 ) { return from_c+1; }
		if( from_c == 7690 ) { return from_c+1; }
		if( from_c == 7692 ) { return from_c+1; }
		if( from_c == 7694 ) { return from_c+1; }
		if( from_c == 7696 ) { return from_c+1; }
		if( from_c == 7698 ) { return from_c+1; }
		if( from_c == 7700 ) { return from_c+1; }
		if( from_c == 7702 ) { return from_c+1; }
		if( from_c == 7704 ) { return from_c+1; }
		if( from_c == 7706 ) { return from_c+1; }
		if( from_c == 7708 ) { return from_c+1; }
		if( from_c == 7710 ) { return from_c+1; }
		if( from_c == 7712 ) { return from_c+1; }
		if( from_c == 7714 ) { return from_c+1; }
		if( from_c == 7716 ) { return from_c+1; }
		if( from_c == 7718 ) { return from_c+1; }
		if( from_c == 7720 ) { return from_c+1; }
		if( from_c == 7722 ) { return from_c+1; }
		if( from_c == 7724 ) { return from_c+1; }
		if( from_c == 7726 ) { return from_c+1; }
		if( from_c == 7728 ) { return from_c+1; }
		if( from_c == 7730 ) { return from_c+1; }
		if( from_c == 7732 ) { return from_c+1; }
		if( from_c == 7734 ) { return from_c+1; }
		if( from_c == 7736 ) { return from_c+1; }
		if( from_c == 7738 ) { return from_c+1; }
		if( from_c == 7740 ) { return from_c+1; }
		if( from_c == 7742 ) { return from_c+1; }
		if( from_c == 7744 ) { return from_c+1; }
		if( from_c == 7746 ) { return from_c+1; }
		if( from_c == 7748 ) { return from_c+1; }
		if( from_c == 7750 ) { return from_c+1; }
		if( from_c == 7752 ) { return from_c+1; }
		if( from_c == 7754 ) { return from_c+1; }
		if( from_c == 7756 ) { return from_c+1; }
		if( from_c == 7758 ) { return from_c+1; }
		if( from_c == 7760 ) { return from_c+1; }
		if( from_c == 7762 ) { return from_c+1; }
		if( from_c == 7764 ) { return from_c+1; }
		if( from_c == 7766 ) { return from_c+1; }
		if( from_c == 7768 ) { return from_c+1; }
		if( from_c == 7770 ) { return from_c+1; }
		if( from_c == 7772 ) { return from_c+1; }
		if( from_c == 7774 ) { return from_c+1; }
		if( from_c == 7776 ) { return from_c+1; }
		if( from_c == 7778 ) { return from_c+1; }
		if( from_c == 7780 ) { return from_c+1; }
		if( from_c == 7782 ) { return from_c+1; }
		if( from_c == 7784 ) { return from_c+1; }
		if( from_c == 7786 ) { return from_c+1; }
		if( from_c == 7788 ) { return from_c+1; }
		if( from_c == 7790 ) { return from_c+1; }
		if( from_c == 7792 ) { return from_c+1; }
		if( from_c == 7794 ) { return from_c+1; }
		if( from_c == 7796 ) { return from_c+1; }
		if( from_c == 7798 ) { return from_c+1; }
		if( from_c == 7800 ) { return from_c+1; }
		if( from_c == 7802 ) { return from_c+1; }
		if( from_c == 7804 ) { return from_c+1; }
		if( from_c == 7806 ) { return from_c+1; }
		if( from_c == 7808 ) { return from_c+1; }
		if( from_c == 7810 ) { return from_c+1; }
		if( from_c == 7812 ) { return from_c+1; }
		if( from_c == 7814 ) { return from_c+1; }
		if( from_c == 7816 ) { return from_c+1; }
		if( from_c == 7818 ) { return from_c+1; }
		if( from_c == 7820 ) { return from_c+1; }
		if( from_c == 7822 ) { return from_c+1; }
		if( from_c == 7824 ) { return from_c+1; }
		if( from_c == 7826 ) { return from_c+1; }
		if( from_c == 7828 ) { return from_c+1; }
		if( from_c == 7840 ) { return from_c+1; }
		if( from_c == 7842 ) { return from_c+1; }
		if( from_c == 7844 ) { return from_c+1; }
		if( from_c == 7846 ) { return from_c+1; }
		if( from_c == 7848 ) { return from_c+1; }
		if( from_c == 7850 ) { return from_c+1; }
		if( from_c == 7852 ) { return from_c+1; }
		if( from_c == 7854 ) { return from_c+1; }
		if( from_c == 7856 ) { return from_c+1; }
		if( from_c == 7858 ) { return from_c+1; }
		if( from_c == 7860 ) { return from_c+1; }
		if( from_c == 7862 ) { return from_c+1; }
		if( from_c == 7864 ) { return from_c+1; }
		if( from_c == 7866 ) { return from_c+1; }
		if( from_c == 7868 ) { return from_c+1; }
		if( from_c == 7870 ) { return from_c+1; }
		if( from_c == 7872 ) { return from_c+1; }
		if( from_c == 7874 ) { return from_c+1; }
		if( from_c == 7876 ) { return from_c+1; }
		if( from_c == 7878 ) { return from_c+1; }
		if( from_c == 7880 ) { return from_c+1; }
		if( from_c == 7882 ) { return from_c+1; }
		if( from_c == 7884 ) { return from_c+1; }
		if( from_c == 7886 ) { return from_c+1; }
		if( from_c == 7888 ) { return from_c+1; }
		if( from_c == 7890 ) { return from_c+1; }
		if( from_c == 7892 ) { return from_c+1; }
		if( from_c == 7894 ) { return from_c+1; }
		if( from_c == 7896 ) { return from_c+1; }
		if( from_c == 7898 ) { return from_c+1; }
		if( from_c == 7900 ) { return from_c+1; }
		if( from_c == 7902 ) { return from_c+1; }
		if( from_c == 7904 ) { return from_c+1; }
		if( from_c == 7906 ) { return from_c+1; }
		if( from_c == 7908 ) { return from_c+1; }
		if( from_c == 7910 ) { return from_c+1; }
		if( from_c == 7912 ) { return from_c+1; }
		if( from_c == 7914 ) { return from_c+1; }
		if( from_c == 7916 ) { return from_c+1; }
		if( from_c == 7918 ) { return from_c+1; }
		if( from_c == 7920 ) { return from_c+1; }
		if( from_c == 7922 ) { return from_c+1; }
		if( from_c == 7924 ) { return from_c+1; }
		if( from_c == 7926 ) { return from_c+1; }
		if( from_c == 7928 ) { return from_c+1; }
		if( from_c == 7930 ) { return from_c+1; }
		if( from_c == 7932 ) { return from_c+1; }
		if( from_c == 7934 ) { return from_c+1; }
		if( from_c == 8579 ) { return from_c+1; }
		if( from_c == 11360 ) { return from_c+1; }
		if( from_c == 11367 ) { return from_c+1; }
		if( from_c == 11369 ) { return from_c+1; }
		if( from_c == 11371 ) { return from_c+1; }
		if( from_c == 11378 ) { return from_c+1; }
		if( from_c == 11381 ) { return from_c+1; }
		if( from_c == 11392 ) { return from_c+1; }
		if( from_c == 11394 ) { return from_c+1; }
		if( from_c == 11396 ) { return from_c+1; }
		if( from_c == 11398 ) { return from_c+1; }
		if( from_c == 11400 ) { return from_c+1; }
		if( from_c == 11402 ) { return from_c+1; }
		if( from_c == 11404 ) { return from_c+1; }
		if( from_c == 11406 ) { return from_c+1; }
		if( from_c == 11408 ) { return from_c+1; }
		if( from_c == 11410 ) { return from_c+1; }
		if( from_c == 11412 ) { return from_c+1; }
		if( from_c == 11414 ) { return from_c+1; }
		if( from_c == 11416 ) { return from_c+1; }
		if( from_c == 11418 ) { return from_c+1; }
		if( from_c == 11420 ) { return from_c+1; }
		if( from_c == 11422 ) { return from_c+1; }
		if( from_c == 11424 ) { return from_c+1; }
		if( from_c == 11426 ) { return from_c+1; }
		if( from_c == 11428 ) { return from_c+1; }
		if( from_c == 11430 ) { return from_c+1; }
		if( from_c == 11432 ) { return from_c+1; }
		if( from_c == 11434 ) { return from_c+1; }
		if( from_c == 11436 ) { return from_c+1; }
		if( from_c == 11438 ) { return from_c+1; }
		if( from_c == 11440 ) { return from_c+1; }
		if( from_c == 11442 ) { return from_c+1; }
		if( from_c == 11444 ) { return from_c+1; }
		if( from_c == 11446 ) { return from_c+1; }
		if( from_c == 11448 ) { return from_c+1; }
		if( from_c == 11450 ) { return from_c+1; }
		if( from_c == 11452 ) { return from_c+1; }
		if( from_c == 11454 ) { return from_c+1; }
		if( from_c == 11456 ) { return from_c+1; }
		if( from_c == 11458 ) { return from_c+1; }
		if( from_c == 11460 ) { return from_c+1; }
		if( from_c == 11462 ) { return from_c+1; }
		if( from_c == 11464 ) { return from_c+1; }
		if( from_c == 11466 ) { return from_c+1; }
		if( from_c == 11468 ) { return from_c+1; }
		if( from_c == 11470 ) { return from_c+1; }
		if( from_c == 11472 ) { return from_c+1; }
		if( from_c == 11474 ) { return from_c+1; }
		if( from_c == 11476 ) { return from_c+1; }
		if( from_c == 11478 ) { return from_c+1; }
		if( from_c == 11480 ) { return from_c+1; }
		if( from_c == 11482 ) { return from_c+1; }
		if( from_c == 11484 ) { return from_c+1; }
		if( from_c == 11486 ) { return from_c+1; }
		if( from_c == 11488 ) { return from_c+1; }
		if( from_c == 11490 ) { return from_c+1; }
		if( from_c == 11499 ) { return from_c+1; }
		if( from_c == 11501 ) { return from_c+1; }
		if( from_c == 11506 ) { return from_c+1; }
		if( from_c == 42560 ) { return from_c+1; }
		if( from_c == 42562 ) { return from_c+1; }
		if( from_c == 42564 ) { return from_c+1; }
		if( from_c == 42566 ) { return from_c+1; }
		if( from_c == 42568 ) { return from_c+1; }
		if( from_c == 42570 ) { return from_c+1; }
		if( from_c == 42572 ) { return from_c+1; }
		if( from_c == 42574 ) { return from_c+1; }
		if( from_c == 42576 ) { return from_c+1; }
		if( from_c == 42578 ) { return from_c+1; }
		if( from_c == 42580 ) { return from_c+1; }
		if( from_c == 42582 ) { return from_c+1; }
		if( from_c == 42584 ) { return from_c+1; }
		if( from_c == 42586 ) { return from_c+1; }
		if( from_c == 42588 ) { return from_c+1; }
		if( from_c == 42590 ) { return from_c+1; }
		if( from_c == 42592 ) { return from_c+1; }
		if( from_c == 42594 ) { return from_c+1; }
		if( from_c == 42596 ) { return from_c+1; }
		if( from_c == 42598 ) { return from_c+1; }
		if( from_c == 42600 ) { return from_c+1; }
		if( from_c == 42602 ) { return from_c+1; }
		if( from_c == 42604 ) { return from_c+1; }
		if( from_c == 42624 ) { return from_c+1; }
		if( from_c == 42626 ) { return from_c+1; }
		if( from_c == 42628 ) { return from_c+1; }
		if( from_c == 42630 ) { return from_c+1; }
		if( from_c == 42632 ) { return from_c+1; }
		if( from_c == 42634 ) { return from_c+1; }
		if( from_c == 42636 ) { return from_c+1; }
		if( from_c == 42638 ) { return from_c+1; }
		if( from_c == 42640 ) { return from_c+1; }
		if( from_c == 42642 ) { return from_c+1; }
		if( from_c == 42644 ) { return from_c+1; }
		if( from_c == 42646 ) { return from_c+1; }
		if( from_c == 42648 ) { return from_c+1; }
		if( from_c == 42650 ) { return from_c+1; }
		if( from_c == 42786 ) { return from_c+1; }
		if( from_c == 42788 ) { return from_c+1; }
		if( from_c == 42790 ) { return from_c+1; }
		if( from_c == 42792 ) { return from_c+1; }
		if( from_c == 42794 ) { return from_c+1; }
		if( from_c == 42796 ) { return from_c+1; }
		if( from_c == 42798 ) { return from_c+1; }
		if( from_c == 42802 ) { return from_c+1; }
		if( from_c == 42804 ) { return from_c+1; }
		if( from_c == 42806 ) { return from_c+1; }
		if( from_c == 42808 ) { return from_c+1; }
		if( from_c == 42810 ) { return from_c+1; }
		if( from_c == 42812 ) { return from_c+1; }
		if( from_c == 42814 ) { return from_c+1; }
		if( from_c == 42816 ) { return from_c+1; }
		if( from_c == 42818 ) { return from_c+1; }
		if( from_c == 42820 ) { return from_c+1; }
		if( from_c == 42822 ) { return from_c+1; }
		if( from_c == 42824 ) { return from_c+1; }
		if( from_c == 42826 ) { return from_c+1; }
		if( from_c == 42828 ) { return from_c+1; }
		if( from_c == 42830 ) { return from_c+1; }
		if( from_c == 42832 ) { return from_c+1; }
		if( from_c == 42834 ) { return from_c+1; }
		if( from_c == 42836 ) { return from_c+1; }
		if( from_c == 42838 ) { return from_c+1; }
		if( from_c == 42840 ) { return from_c+1; }
		if( from_c == 42842 ) { return from_c+1; }
		if( from_c == 42844 ) { return from_c+1; }
		if( from_c == 42846 ) { return from_c+1; }
		if( from_c == 42848 ) { return from_c+1; }
		if( from_c == 42850 ) { return from_c+1; }
		if( from_c == 42852 ) { return from_c+1; }
		if( from_c == 42854 ) { return from_c+1; }
		if( from_c == 42856 ) { return from_c+1; }
		if( from_c == 42858 ) { return from_c+1; }
		if( from_c == 42860 ) { return from_c+1; }
		if( from_c == 42862 ) { return from_c+1; }
		if( from_c == 42873 ) { return from_c+1; }
		if( from_c == 42875 ) { return from_c+1; }
		if( from_c == 42878 ) { return from_c+1; }
		if( from_c == 42880 ) { return from_c+1; }
		if( from_c == 42882 ) { return from_c+1; }
		if( from_c == 42884 ) { return from_c+1; }
		if( from_c == 42886 ) { return from_c+1; }
		if( from_c == 42891 ) { return from_c+1; }
		if( from_c == 42896 ) { return from_c+1; }
		if( from_c == 42898 ) { return from_c+1; }
		if( from_c == 42902 ) { return from_c+1; }
		if( from_c == 42904 ) { return from_c+1; }
		if( from_c == 42906 ) { return from_c+1; }
		if( from_c == 42908 ) { return from_c+1; }
		if( from_c == 42910 ) { return from_c+1; }
		if( from_c == 42912 ) { return from_c+1; }
		if( from_c == 42914 ) { return from_c+1; }
		if( from_c == 42916 ) { return from_c+1; }
		if( from_c == 42918 ) { return from_c+1; }
		if( from_c == 42920 ) { return from_c+1; }
		if( from_c == 42932 ) { return from_c+1; }
		if( from_c == 42934 ) { return from_c+1; }
		if( from_c == 42936 ) { return from_c+1; }
		if( from_c == 42938 ) { return from_c+1; }
		if( from_c == 42940 ) { return from_c+1; }
		if( from_c == 42942 ) { return from_c+1; }
		if( from_c == 42944 ) { return from_c+1; }
		if( from_c == 42946 ) { return from_c+1; }
		if( from_c == 42951 ) { return from_c+1; }
		if( from_c == 42953 ) { return from_c+1; }
		if( from_c == 42960 ) { return from_c+1; }
		if( from_c == 42966 ) { return from_c+1; }
		if( from_c == 42968 ) { return from_c+1; }
		if( from_c == 42997 ) { return from_c+1; }
		if( from_c == 376 ) { return from_c-121; }
		if( from_c == 385 ) { return from_c+210; }
		if( from_c == 390 ) { return from_c+206; }
		if( from_c >= 393 && from_c < 395 ) { return from_c+205; }
		if( from_c == 403 ) { return from_c+205; }
		if( from_c == 398 ) { return from_c+79; }
		if( from_c == 399 ) { return from_c+202; }
		if( from_c == 400 ) { return from_c+203; }
		if( from_c == 404 ) { return from_c+207; }
		if( from_c == 406 ) { return from_c+211; }
		if( from_c == 412 ) { return from_c+211; }
		if( from_c == 407 ) { return from_c+209; }
		if( from_c == 413 ) { return from_c+213; }
		if( from_c == 415 ) { return from_c+214; }
		if( from_c == 422 ) { return from_c+218; }
		if( from_c == 425 ) { return from_c+218; }
		if( from_c == 430 ) { return from_c+218; }
		if( from_c >= 433 && from_c < 435 ) { return from_c+217; }
		if( from_c == 439 ) { return from_c+219; }
		if( from_c == 452 ) { return from_c+2; }
		if( from_c == 455 ) { return from_c+2; }
		if( from_c == 458 ) { return from_c+2; }
		if( from_c == 497 ) { return from_c+2; }
		if( from_c == 502 ) { return from_c-97; }
		if( from_c == 503 ) { return from_c-56; }
		if( from_c == 544 ) { return from_c-130; }
		if( from_c >= 1021 && from_c < 1024 ) { return from_c-130; }
		if( from_c == 570 ) { return from_c+10795; }
		if( from_c == 573 ) { return from_c-163; }
		if( from_c == 574 ) { return from_c+10792; }
		if( from_c == 579 ) { return from_c-195; }
		if( from_c == 580 ) { return from_c+69; }
		if( from_c == 581 ) { return from_c+71; }
		if( from_c == 895 ) { return from_c+116; }
		if( from_c == 902 ) { return from_c+38; }
		if( from_c >= 904 && from_c < 907 ) { return from_c+37; }
		if( from_c == 908 ) { return from_c+64; }
		if( from_c >= 68736 && from_c < 68787 ) { return from_c+64; }
		if( from_c >= 910 && from_c < 912 ) { return from_c+63; }
		if( from_c == 975 ) { return from_c+8; }
		if( from_c >= 5104 && from_c < 5110 ) { return from_c+8; }
		if( from_c == 1012 ) { return from_c-60; }
		if( from_c == 1017 ) { return from_c-7; }
		if( from_c == 8172 ) { return from_c-7; }
		if( from_c >= 1024 && from_c < 1040 ) { return from_c+80; }
		if( from_c == 1216 ) { return from_c+15; }
		if( from_c >= 1329 && from_c < 1367 ) { return from_c+48; }
		if( from_c >= 11264 && from_c < 11312 ) { return from_c+48; }
		if( from_c >= 4256 && from_c < 4294 ) { return from_c+7264; }
		if( from_c == 4295 ) { return from_c+7264; }
		if( from_c == 4301 ) { return from_c+7264; }
		if( from_c >= 5024 && from_c < 5104 ) { return from_c+38864; }
		if( from_c >= 7312 && from_c < 7355 ) { return from_c-3008; }
		if( from_c >= 7357 && from_c < 7360 ) { return from_c-3008; }
		if( from_c == 7838 ) { return from_c-7615; }
		if( from_c >= 7944 && from_c < 7952 ) { return from_c-8; }
		if( from_c >= 7960 && from_c < 7966 ) { return from_c-8; }
		if( from_c >= 7976 && from_c < 7984 ) { return from_c-8; }
		if( from_c >= 7992 && from_c < 8000 ) { return from_c-8; }
		if( from_c >= 8008 && from_c < 8014 ) { return from_c-8; }
		if( from_c == 8025 ) { return from_c-8; }
		if( from_c == 8027 ) { return from_c-8; }
		if( from_c == 8029 ) { return from_c-8; }
		if( from_c == 8031 ) { return from_c-8; }
		if( from_c >= 8040 && from_c < 8048 ) { return from_c-8; }
		if( from_c >= 8072 && from_c < 8080 ) { return from_c-8; }
		if( from_c >= 8088 && from_c < 8096 ) { return from_c-8; }
		if( from_c >= 8104 && from_c < 8112 ) { return from_c-8; }
		if( from_c >= 8120 && from_c < 8122 ) { return from_c-8; }
		if( from_c >= 8152 && from_c < 8154 ) { return from_c-8; }
		if( from_c >= 8168 && from_c < 8170 ) { return from_c-8; }
		if( from_c >= 8122 && from_c < 8124 ) { return from_c-74; }
		if( from_c == 8124 ) { return from_c-9; }
		if( from_c == 8140 ) { return from_c-9; }
		if( from_c == 8188 ) { return from_c-9; }
		if( from_c >= 8136 && from_c < 8140 ) { return from_c-86; }
		if( from_c >= 8154 && from_c < 8156 ) { return from_c-100; }
		if( from_c >= 8170 && from_c < 8172 ) { return from_c-112; }
		if( from_c >= 8184 && from_c < 8186 ) { return from_c-128; }
		if( from_c >= 8186 && from_c < 8188 ) { return from_c-126; }
		if( from_c == 8486 ) { return from_c-7517; }
		if( from_c == 8490 ) { return from_c-8383; }
		if( from_c == 8491 ) { return from_c-8262; }
		if( from_c == 8498 ) { return from_c+28; }
		if( from_c >= 8544 && from_c < 8560 ) { return from_c+16; }
		if( from_c >= 9398 && from_c < 9424 ) { return from_c+26; }
		if( from_c == 11362 ) { return from_c-10743; }
		if( from_c == 11363 ) { return from_c-3814; }
		if( from_c == 11364 ) { return from_c-10727; }
		if( from_c == 11373 ) { return from_c-10780; }
		if( from_c == 11374 ) { return from_c-10749; }
		if( from_c == 11375 ) { return from_c-10783; }
		if( from_c == 11376 ) { return from_c-10782; }
		if( from_c >= 11390 && from_c < 11392 ) { return from_c-10815; }
		if( from_c == 42877 ) { return from_c-35332; }
		if( from_c == 42893 ) { return from_c-42280; }
		if( from_c == 42922 ) { return from_c-42308; }
		if( from_c == 42926 ) { return from_c-42308; }
		if( from_c == 42923 ) { return from_c-42319; }
		if( from_c == 42924 ) { return from_c-42315; }
		if( from_c == 42925 ) { return from_c-42305; }
		if( from_c == 42928 ) { return from_c-42258; }
		if( from_c == 42929 ) { return from_c-42282; }
		if( from_c == 42930 ) { return from_c-42261; }
		if( from_c == 42931 ) { return from_c+928; }
		if( from_c == 42948 ) { return from_c-48; }
		if( from_c == 42949 ) { return from_c-42307; }
		if( from_c == 42950 ) { return from_c-35384; }
		if( from_c >= 66560 && from_c < 66600 ) { return from_c+40; }
		if( from_c >= 66736 && from_c < 66772 ) { return from_c+40; }
		if( from_c >= 66928 && from_c < 66939 ) { return from_c+39; }
		if( from_c >= 66940 && from_c < 66955 ) { return from_c+39; }
		if( from_c >= 66956 && from_c < 66963 ) { return from_c+39; }
		if( from_c >= 66964 && from_c < 66966 ) { return from_c+39; }
		if( from_c >= 125184 && from_c < 125218 ) { return from_c+34; }

		return from_c;
	}
	
	std::u32string to_upper(const std::u32string& from_string) noexcept {
		std::u32string result{};
		result.reserve(from_string.length());
		for(char32_t from_c : from_string) {
			if( from_c == 223 ){ //ß => SS
				result += U"SS";
				continue;
			}
			if( from_c == 329 ){ //ŉ => ʼN
				result += U"ʼN";
				continue;
			}
			if( from_c == 496 ){ //ǰ => J̌
				result += U"J̌";
				continue;
			}
			if( from_c == 912 ){ //ΐ => Ϊ́
				result += U"Ϊ́";
				continue;
			}
			if( from_c == 944 ){ //ΰ => Ϋ́
				result += U"Ϋ́";
				continue;
			}
			if( from_c == 1415 ){ //և => ԵՒ
				result += U"ԵՒ";
				continue;
			}
			if( from_c == 7830 ){ //ẖ => H̱
				result += U"H̱";
				continue;
			}
			if( from_c == 7831 ){ //ẗ => T̈
				result += U"T̈";
				continue;
			}
			if( from_c == 7832 ){ //ẘ => W̊
				result += U"W̊";
				continue;
			}
			if( from_c == 7833 ){ //ẙ => Y̊
				result += U"Y̊";
				continue;
			}
			if( from_c == 7834 ){ //ẚ => Aʾ
				result += U"Aʾ";
				continue;
			}
			if( from_c == 8016 ){ //ὐ => Υ̓
				result += U"Υ̓";
				continue;
			}
			if( from_c == 8018 ){ //ὒ => Υ̓̀
				result += U"Υ̓̀";
				continue;
			}
			if( from_c == 8020 ){ //ὔ => Υ̓́
				result += U"Υ̓́";
				continue;
			}
			if( from_c == 8022 ){ //ὖ => Υ̓͂
				result += U"Υ̓͂";
				continue;
			}
			if( from_c == 8064 ){ //ᾀ => ἈΙ
				result += U"ἈΙ";
				continue;
			}
			if( from_c == 8065 ){ //ᾁ => ἉΙ
				result += U"ἉΙ";
				continue;
			}
			if( from_c == 8066 ){ //ᾂ => ἊΙ
				result += U"ἊΙ";
				continue;
			}
			if( from_c == 8067 ){ //ᾃ => ἋΙ
				result += U"ἋΙ";
				continue;
			}
			if( from_c == 8068 ){ //ᾄ => ἌΙ
				result += U"ἌΙ";
				continue;
			}
			if( from_c == 8069 ){ //ᾅ => ἍΙ
				result += U"ἍΙ";
				continue;
			}
			if( from_c == 8070 ){ //ᾆ => ἎΙ
				result += U"ἎΙ";
				continue;
			}
			if( from_c == 8071 ){ //ᾇ => ἏΙ
				result += U"ἏΙ";
				continue;
			}
			if( from_c == 8072 ){ //ᾈ => ἈΙ
				result += U"ἈΙ";
				continue;
			}
			if( from_c == 8073 ){ //ᾉ => ἉΙ
				result += U"ἉΙ";
				continue;
			}
			if( from_c == 8074 ){ //ᾊ => ἊΙ
				result += U"ἊΙ";
				continue;
			}
			if( from_c == 8075 ){ //ᾋ => ἋΙ
				result += U"ἋΙ";
				continue;
			}
			if( from_c == 8076 ){ //ᾌ => ἌΙ
				result += U"ἌΙ";
				continue;
			}
			if( from_c == 8077 ){ //ᾍ => ἍΙ
				result += U"ἍΙ";
				continue;
			}
			if( from_c == 8078 ){ //ᾎ => ἎΙ
				result += U"ἎΙ";
				continue;
			}
			if( from_c == 8079 ){ //ᾏ => ἏΙ
				result += U"ἏΙ";
				continue;
			}
			if( from_c == 8080 ){ //ᾐ => ἨΙ
				result += U"ἨΙ";
				continue;
			}
			if( from_c == 8081 ){ //ᾑ => ἩΙ
				result += U"ἩΙ";
				continue;
			}
			if( from_c == 8082 ){ //ᾒ => ἪΙ
				result += U"ἪΙ";
				continue;
			}
			if( from_c == 8083 ){ //ᾓ => ἫΙ
				result += U"ἫΙ";
				continue;
			}
			if( from_c == 8084 ){ //ᾔ => ἬΙ
				result += U"ἬΙ";
				continue;
			}
			if( from_c == 8085 ){ //ᾕ => ἭΙ
				result += U"ἭΙ";
				continue;
			}
			if( from_c == 8086 ){ //ᾖ => ἮΙ
				result += U"ἮΙ";
				continue;
			}
			if( from_c == 8087 ){ //ᾗ => ἯΙ
				result += U"ἯΙ";
				continue;
			}
			if( from_c == 8088 ){ //ᾘ => ἨΙ
				result += U"ἨΙ";
				continue;
			}
			if( from_c == 8089 ){ //ᾙ => ἩΙ
				result += U"ἩΙ";
				continue;
			}
			if( from_c == 8090 ){ //ᾚ => ἪΙ
				result += U"ἪΙ";
				continue;
			}
			if( from_c == 8091 ){ //ᾛ => ἫΙ
				result += U"ἫΙ";
				continue;
			}
			if( from_c == 8092 ){ //ᾜ => ἬΙ
				result += U"ἬΙ";
				continue;
			}
			if( from_c == 8093 ){ //ᾝ => ἭΙ
				result += U"ἭΙ";
				continue;
			}
			if( from_c == 8094 ){ //ᾞ => ἮΙ
				result += U"ἮΙ";
				continue;
			}
			if( from_c == 8095 ){ //ᾟ => ἯΙ
				result += U"ἯΙ";
				continue;
			}
			if( from_c == 8096 ){ //ᾠ => ὨΙ
				result += U"ὨΙ";
				continue;
			}
			if( from_c == 8097 ){ //ᾡ => ὩΙ
				result += U"ὩΙ";
				continue;
			}
			if( from_c == 8098 ){ //ᾢ => ὪΙ
				result += U"ὪΙ";
				continue;
			}
			if( from_c == 8099 ){ //ᾣ => ὫΙ
				result += U"ὫΙ";
				continue;
			}
			if( from_c == 8100 ){ //ᾤ => ὬΙ
				result += U"ὬΙ";
				continue;
			}
			if( from_c == 8101 ){ //ᾥ => ὭΙ
				result += U"ὭΙ";
				continue;
			}
			if( from_c == 8102 ){ //ᾦ => ὮΙ
				result += U"ὮΙ";
				continue;
			}
			if( from_c == 8103 ){ //ᾧ => ὯΙ
				result += U"ὯΙ";
				continue;
			}
			if( from_c == 8104 ){ //ᾨ => ὨΙ
				result += U"ὨΙ";
				continue;
			}
			if( from_c == 8105 ){ //ᾩ => ὩΙ
				result += U"ὩΙ";
				continue;
			}
			if( from_c == 8106 ){ //ᾪ => ὪΙ
				result += U"ὪΙ";
				continue;
			}
			if( from_c == 8107 ){ //ᾫ => ὫΙ
				result += U"ὫΙ";
				continue;
			}
			if( from_c == 8108 ){ //ᾬ => ὬΙ
				result += U"ὬΙ";
				continue;
			}
			if( from_c == 8109 ){ //ᾭ => ὭΙ
				result += U"ὭΙ";
				continue;
			}
			if( from_c == 8110 ){ //ᾮ => ὮΙ
				result += U"ὮΙ";
				continue;
			}
			if( from_c == 8111 ){ //ᾯ => ὯΙ
				result += U"ὯΙ";
				continue;
			}
			if( from_c == 8114 ){ //ᾲ => ᾺΙ
				result += U"ᾺΙ";
				continue;
			}
			if( from_c == 8115 ){ //ᾳ => ΑΙ
				result += U"ΑΙ";
				continue;
			}
			if( from_c == 8116 ){ //ᾴ => ΆΙ
				result += U"ΆΙ";
				continue;
			}
			if( from_c == 8118 ){ //ᾶ => Α͂
				result += U"Α͂";
				continue;
			}
			if( from_c == 8119 ){ //ᾷ => Α͂Ι
				result += U"Α͂Ι";
				continue;
			}
			if( from_c == 8124 ){ //ᾼ => ΑΙ
				result += U"ΑΙ";
				continue;
			}
			if( from_c == 8130 ){ //ῂ => ῊΙ
				result += U"ῊΙ";
				continue;
			}
			if( from_c == 8131 ){ //ῃ => ΗΙ
				result += U"ΗΙ";
				continue;
			}
			if( from_c == 8132 ){ //ῄ => ΉΙ
				result += U"ΉΙ";
				continue;
			}
			if( from_c == 8134 ){ //ῆ => Η͂
				result += U"Η͂";
				continue;
			}
			if( from_c == 8135 ){ //ῇ => Η͂Ι
				result += U"Η͂Ι";
				continue;
			}
			if( from_c == 8140 ){ //ῌ => ΗΙ
				result += U"ΗΙ";
				continue;
			}
			if( from_c == 8146 ){ //ῒ => Ϊ̀
				result += U"Ϊ̀";
				continue;
			}
			if( from_c == 8147 ){ //ΐ => Ϊ́
				result += U"Ϊ́";
				continue;
			}
			if( from_c == 8150 ){ //ῖ => Ι͂
				result += U"Ι͂";
				continue;
			}
			if( from_c == 8151 ){ //ῗ => Ϊ͂
				result += U"Ϊ͂";
				continue;
			}
			if( from_c == 8162 ){ //ῢ => Ϋ̀
				result += U"Ϋ̀";
				continue;
			}
			if( from_c == 8163 ){ //ΰ => Ϋ́
				result += U"Ϋ́";
				continue;
			}
			if( from_c == 8164 ){ //ῤ => Ρ̓
				result += U"Ρ̓";
				continue;
			}
			if( from_c == 8166 ){ //ῦ => Υ͂
				result += U"Υ͂";
				continue;
			}
			if( from_c == 8167 ){ //ῧ => Ϋ͂
				result += U"Ϋ͂";
				continue;
			}
			if( from_c == 8178 ){ //ῲ => ῺΙ
				result += U"ῺΙ";
				continue;
			}
			if( from_c == 8179 ){ //ῳ => ΩΙ
				result += U"ΩΙ";
				continue;
			}
			if( from_c == 8180 ){ //ῴ => ΏΙ
				result += U"ΏΙ";
				continue;
			}
			if( from_c == 8182 ){ //ῶ => Ω͂
				result += U"Ω͂";
				continue;
			}
			if( from_c == 8183 ){ //ῷ => Ω͂Ι
				result += U"Ω͂Ι";
				continue;
			}
			if( from_c == 8188 ){ //ῼ => ΩΙ
				result += U"ΩΙ";
				continue;
			}
			if( from_c == 64256 ){ //ﬀ => FF
				result += U"FF";
				continue;
			}
			if( from_c == 64257 ){ //ﬁ => FI
				result += U"FI";
				continue;
			}
			if( from_c == 64258 ){ //ﬂ => FL
				result += U"FL";
				continue;
			}
			if( from_c == 64259 ){ //ﬃ => FFI
				result += U"FFI";
				continue;
			}
			if( from_c == 64260 ){ //ﬄ => FFL
				result += U"FFL";
				continue;
			}
			if( from_c == 64261 ){ //ﬅ => ST
				result += U"ST";
				continue;
			}
			if( from_c == 64262 ){ //ﬆ => ST
				result += U"ST";
				continue;
			}
			if( from_c == 64275 ){ //ﬓ => ՄՆ
				result += U"ՄՆ";
				continue;
			}
			if( from_c == 64276 ){ //ﬔ => ՄԵ
				result += U"ՄԵ";
				continue;
			}
			if( from_c == 64277 ){ //ﬕ => ՄԻ
				result += U"ՄԻ";
				continue;
			}
			if( from_c == 64278 ){ //ﬖ => ՎՆ
				result += U"ՎՆ";
				continue;
			}
			if( from_c == 64279 ){ //ﬗ => ՄԽ
				result += U"ՄԽ";
				continue;
			}
			
			result += to_upper(from_c);
		}
		return result;
	}
	
	std::u32string to_lower(const std::u32string& from_string) noexcept {
		std::u32string result{};
		result.reserve(from_string.length());
		for(char32_t from_c : from_string) {
			if( from_c == 304 ){ //İ => i̇
				result += U"i̇";
				continue;
			}
			
			result += to_lower(from_c);
		}
		return result;
	}
	
}

