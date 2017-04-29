

<p>
    <strong>PORTFOLIO </strong>
</p>

<table class="table table-hover">
    <thead>
        <tr>
            <th>Symbol</th>
            <th>Name</th>
            <th>Shares</th>
            <th>Price </th>
            <th>Total </th>
            
        </tr>
    </thead>
    <tbody>
        <?php foreach($shares as $share): ?>
            <tr>
                <td><?= $share["symbol"] ?></td>
                <td><?= $share["name"] ?></td>
                <td><?= $share["shares"] ?></td>
                <td><?= "$ ".number_format($share["price"], 2) ?></td>
                <td><?= "$ ".number_format($share["total"], 2) ?></td>
        <?php endforeach ?>
         </tr>
         
        
        
    </tbody>
     
</table>

<p><strong> <?= "CASH BALANCE:    You have"."  $ ". number_format($cash[0]['cash'],2) . "  dollars available." ?></strong></p>

