// Generated from bash.g4 by ANTLR 4.7.1
import org.antlr.v4.runtime.tree.ParseTreeListener;

/**
 * This interface defines a complete listener for a parse tree produced by
 * {@link bashParser}.
 */
public interface bashListener extends ParseTreeListener {
	/**
	 * Enter a parse tree produced by {@link bashParser#expression}.
	 * @param ctx the parse tree
	 */
	void enterExpression(bashParser.ExpressionContext ctx);
	/**
	 * Exit a parse tree produced by {@link bashParser#expression}.
	 * @param ctx the parse tree
	 */
	void exitExpression(bashParser.ExpressionContext ctx);
	/**
	 * Enter a parse tree produced by {@link bashParser#command}.
	 * @param ctx the parse tree
	 */
	void enterCommand(bashParser.CommandContext ctx);
	/**
	 * Exit a parse tree produced by {@link bashParser#command}.
	 * @param ctx the parse tree
	 */
	void exitCommand(bashParser.CommandContext ctx);
	/**
	 * Enter a parse tree produced by {@link bashParser#peremeter}.
	 * @param ctx the parse tree
	 */
	void enterPeremeter(bashParser.PeremeterContext ctx);
	/**
	 * Exit a parse tree produced by {@link bashParser#peremeter}.
	 * @param ctx the parse tree
	 */
	void exitPeremeter(bashParser.PeremeterContext ctx);
	/**
	 * Enter a parse tree produced by {@link bashParser#string}.
	 * @param ctx the parse tree
	 */
	void enterString(bashParser.StringContext ctx);
	/**
	 * Exit a parse tree produced by {@link bashParser#string}.
	 * @param ctx the parse tree
	 */
	void exitString(bashParser.StringContext ctx);
	/**
	 * Enter a parse tree produced by {@link bashParser#path}.
	 * @param ctx the parse tree
	 */
	void enterPath(bashParser.PathContext ctx);
	/**
	 * Exit a parse tree produced by {@link bashParser#path}.
	 * @param ctx the parse tree
	 */
	void exitPath(bashParser.PathContext ctx);
	/**
	 * Enter a parse tree produced by {@link bashParser#object}.
	 * @param ctx the parse tree
	 */
	void enterObject(bashParser.ObjectContext ctx);
	/**
	 * Exit a parse tree produced by {@link bashParser#object}.
	 * @param ctx the parse tree
	 */
	void exitObject(bashParser.ObjectContext ctx);
}