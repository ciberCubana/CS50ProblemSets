<table class="table table-hover">
    <thead>
        <tr>
            <th> Symbol</th>
            <th> Name</th>
            <th> Action</th>
            <th>      Shares</th>
            <th>      Price</th>
            <th>      Date</th>
        </tr>
    </thead>
    <tbody>
        <?php 
       
        foreach($history as $h): ?>
            <tr>
                <td><?= $h["symbol"] ?></td>
                <td><?= $h["name"] ?></td>
                <td><?= $h["action"] ?></td>
                 <td><?= $h["shares"] ?></td>
                <td><?= "$".number_format($h["price"], 2) ?></td>
                <td><?= $h["date"] ?></td>
                
            </tr>
            
        <?php endforeach ?>
        
    </tbody>
</table>