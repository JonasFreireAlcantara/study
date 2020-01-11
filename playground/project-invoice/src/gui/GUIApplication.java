package gui;

import java.io.IOException;
import java.util.Stack;

import business.SystemFacade;
import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class GUIApplication extends Application{
	
	private static Stage mainStage;
	private static Stack<Scene> scenes = new Stack<Scene>();
	private static Stack<String> titles = new Stack<String>();
	private static SystemFacade system;
	
	
	public static void backScene() {
		mainStage.setScene(scenes.pop());
		mainStage.setTitle(titles.pop());

		if(scenes.size() == 0)
			mainStage.close();
	}
	
	
	public static void setScene(Scene newScene) {
		scenes.push(mainStage.getScene());
		mainStage.setScene(newScene);
	}
	
	
	public static void setTitle(String newTitle) {
		titles.push(mainStage.getTitle());
		mainStage.setTitle(newTitle);
	}
	

	public static void main(String[] args) {
		
		system = SystemFacade.getInstance();
		System.out.println("System up");
		
		launch(args);
		
		System.out.println("System down");
		system.shutdownSystem();
	}
	
	
	@Override
	public void start(Stage stage) throws IOException {
		mainStage = stage;
				
		Parent root = FXMLLoader.load(getClass().getResource("fxml/MainMenuLayout.fxml"));
				
		setScene(new Scene(root));
		
		mainStage.show();
	}

}
