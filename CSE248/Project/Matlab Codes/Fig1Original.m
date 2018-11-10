clc;
clear all;
t =[-5 -3 -2 -2 0 1];
x =[2 0 0 1 1 2];

plot(t, x, 'blue', 'LineWidth', 1.5);
grid on;
set(gcf, 'Units', 'Inches', 'Position', [2, 3, 8, 2], 'PaperUnits', 'Inches', 'PaperSize', [8, 2]);

xlabel('t - Time Period');
ylabel('x(t)');

set(gcf, 'PaperUnits', 'inches');
 x_width=8 ;y_width=2;
 set(gcf, 'PaperPosition', [0 0 x_width y_width]);
 saveas(gcf,'fig1Original.jpg');