clc, clear all, close all;

data = load('out.txt')';

i = 10;
idx = 1;
while i <= 100000000    
    figure(idx);
    cur_data = data(:, find(data(1, :)==i));
    cur_data
    plot( cur_data(2,:), cur_data(3,:), 'b*-' );
    hold on, plot( cur_data(2,:), i*log(cur_data(2,:))/log(2), 'r' );
    hold on, plot( cur_data(2,:), i*log(cur_data(2,:)), 'g' );
    title(['n = 10^', num2str(idx)])
    xlabel('m')
    legend('func(m)', 'y=log_2(m)', 'y=ln(m)', 'Location', 'Best')
    i = i * 10;
    idx = idx + 1;
end
