import 'package:flutter/material.dart';
import 'main.dart';

class InputPart extends StatefulWidget {
  final onTabChanged;
  const InputPart({super.key, this.onTabChanged});

  @override
  _InputPartState createState() => _InputPartState();
}

class _InputPartState extends State<InputPart> {
  TextEditingController _controller = TextEditingController();

  @override
  Widget build(BuildContext context) {
    return Row(children: [
      Expanded(
          child: TextField(
        controller: _controller,
        decoration: const InputDecoration(
          labelText: 'Enter your text',
        ),
      )),
      SizedBox(height: 20),
      ElevatedButton(
        onPressed: () {
          String enteredText = _controller.text;
          print('Entered text: $enteredText');
          List<String> newTab = [...MyApp.tab, enteredText];
          widget.onTabChanged(newTab);
          _controller.clear();
          // Vous pouvez utiliser la valeur entrée dans l'application comme bon vous semble
        },
        child: const Text('Submit'),
      ),
    ]);
  }
}
