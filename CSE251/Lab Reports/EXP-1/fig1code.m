clc;
clear all;
x =[0.1015
0.1591
0.2527
0.3340
0.4495
0.4907
0.5127
0.5262
0.5409
0.5517
0.5768
0.5954
0.6086
0.6218
0.6295
0.6387
0.6459
0.6521
0.6578
0.6626
0.6626
];

t =[0
0
0.0001037
0.0009336
0.0224
0.0790
0.1508
0.2291
0.3590
0.4816
0.9230
1.2358
1.7464
2.5529
2.9823
3.5051
3.9263
4.5394
5.1929
5.4574
0
];

plot(x, t, 'blue', 'LineWidth', 1.5);
title('Diode Current VS Diode Voltage');
xlabel('Diode Voltage (Vd)');
ylabel('Diode Current (Id)');
grid on;


set(gcf, 'PaperUnits', 'inches');
 x_width=8 ;y_width=6;
 set(gcf, 'PaperPosition', [0 0 x_width y_width]); %
 saveas(gcf,'fig1.jpg');