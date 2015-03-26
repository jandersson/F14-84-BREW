import QtQuick 2.2
import QtQuick.Dialogs 1.0

FileDialog{
    id: filedialog
    title: "Choose a recipe XML file"
    onAccepted: {
        console.log("File selected: " + filedialog.fileUrl)
        recipe.setImportPath(filedialog.fileUrl)
        console.log("Importing file: " + recipe.getImportPath())
        filedialog.close()
        manager.addRecipe(recipe)
    }
    onRejected: {
        console.log("Operation canceled")
        filedialog.close()
    }




}
