`timescale 1ps/1ps

module test_pli();

reg clk;
initial begin
    clk=0;
    forever begin
        #10;
        clk=~clk;
    end
end


reg signed [7:0] x;
reg signed [7:0] y;
reg signed [7:0] z1;
reg signed [7:0] z2;
reg err;

initial begin
    x=-100;
    y=-100;
    z1=0;
    z2=0;
    err=0;
    repeat(4)@(negedge clk);
    repeat(200) begin
        repeat(200) begin
            @(negedge clk);
            z1=$test(x,y);
            $display("%d + %d = %d",x,y,z1);
            z2=x+y;
            if(z1!=z2) begin
                $display("error at x=%d, y=%d",x,y);
                err=1;
            end
            y=y+1;
        end
        x=x+1;
    end
    if(err) $display("Something is wrong through the calculation.");
    else $display("success");
    $display("Finish");
    $finish;
end

endmodule

