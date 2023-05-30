module FlipFlopCounter (  input wire clock,
  output reg q1,
  output reg q2,
  input wire d
);

  always @(posedge clock) begin
    q1 <= ~q1;
    if (q1 == 1'b1) begin
      q2 <= ~q2;
    end
    d <= q1 ^ q2;
  end

endmodule

module MainModule (
  input wire clock,
  output wire q1,
  output wire q2
);

  wire d;
  reg q1_reg, q2_reg;

  FlipFlopCounter flipflop (
    .clock(clock),
    .q1(q1_reg),
    .q2(q2_reg),
    .d(d)
  );

  always @(posedge clock) begin
    q1_reg <= q1;
    q2_reg <= q2;
  end

endmodule
