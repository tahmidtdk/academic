clc;
clear all;
%t =[-5 -3 -2 -2 0 1];  t will be shifted to t0
t0 = [-7 -5 -4 -4 -2 -1];
x =[2 0 0 1 1 2];
plot(t0, x, 'blue', 'LineWidth', 1.5);

grid on;
set(gcf, 'Units', 'Inches', 'Position', [2, 3, 8, 2], 'PaperUnits', 'Inches', 'PaperSize', [8, 2]);
xlabel('t - Time Period');
ylabel('x(t-2)');

set(gcf, 'PaperUnits', 'inches');
 x_width=8 ;y_width=2;
 set(gcf, 'PaperPosition', [0 0 x_width y_width]); %
 saveas(gcf,'fig2_shift_right.jpg');
