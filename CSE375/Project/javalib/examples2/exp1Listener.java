// Generated from exp1.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link exp1Parser}.
 */
public interface exp1Listener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link exp1Parser#start}.
	 * @param ctx the parse tree
	 */
	void enterStart(exp1Parser.StartContext ctx);
	/**
	 * Exit a parse tree produced by {@link exp1Parser#start}.
	 * @param ctx the parse tree
	 */
	void exitStart(exp1Parser.StartContext ctx);
	/**
	 * Enter a parse tree produced by {@link exp1Parser#expr}.
	 * @param ctx the parse tree
	 */
	void enterExpr(exp1Parser.ExprContext ctx);
	/**
	 * Exit a parse tree produced by {@link exp1Parser#expr}.
	 * @param ctx the parse tree
	 */
	void exitExpr(exp1Parser.ExprContext ctx);
}